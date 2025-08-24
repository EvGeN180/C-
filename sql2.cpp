#include <iostream>
#include <sqlite3.h>
#include <string>

int performDbOperations() {
    sqlite3* db;
    char* zErrMsg = nullptr;
    int rc;

    rc = sqlite3_open("products.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    std::cout << "Opened database successfully\n";

    const char* create_sql = R"(
        CREATE TABLE IF NOT EXISTS Product (
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            NAME TEXT NOT NULL UNIQUE,
            PRICE REAL,
            QUANTITY INTEGER
        );
    )";
    rc = sqlite3_exec(db, create_sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else {
        std::cout << "Table created successfully\n";
    }

    const char* insert_sql = R"(
        INSERT INTO Product (NAME, PRICE, QUANTITY) VALUES
        ('Notebook', 1200.00, 50),
        ('Mouse', 25.50, 200),
        ('Keyboard', 60.00, 150)
        ON CONFLICT(NAME) DO NOTHING;
    )";
    rc = sqlite3_exec(db, insert_sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else {
        std::cout << "Records inserted successfully\n";
    }

    const char* upsert_sql = R"(
        INSERT INTO Product (NAME, PRICE, QUANTITY)
        VALUES (?, ?, ?)
        ON CONFLICT(NAME) DO UPDATE SET
            PRICE = excluded.PRICE,
            QUANTITY = QUANTITY + excluded.QUANTITY;
    )";

    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, upsert_sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
    }
    else {
        std::string product_name = "Monitor";
        double product_price = 260.00;
        int product_quantity = 10;

        sqlite3_bind_text(stmt, 1, product_name.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 2, product_price);
        sqlite3_bind_int(stmt, 3, product_quantity);

        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            std::cerr << "Failed to execute upsert: " << sqlite3_errmsg(db) << std::endl;
        }
        else {
            std::cout << "Upsert operation completed\n";
        }
        sqlite3_finalize(stmt);
    }

    const char* delete_sql = "DELETE FROM Product WHERE QUANTITY = 0;";
    rc = sqlite3_exec(db, delete_sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else {
        std::cout << "Deleted products with zero quantity successfully\n";
    }

    std::cout << "\n All Products\n";
    const char* select_all_sql = "SELECT ID, NAME, PRICE, QUANTITY FROM Product;";
    rc = sqlite3_prepare_v2(db, select_all_sql, -1, &stmt, nullptr);
    if (rc == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char* name = sqlite3_column_text(stmt, 1);
            double price = sqlite3_column_double(stmt, 2);
            int quantity = sqlite3_column_int(stmt, 3);

            std::cout << "ID: " << id << ", Name: " << name
                << ", Price: " << price << ", Quantity: " << quantity << "\n";
        }
        sqlite3_finalize(stmt);
    }
    else {
        std::cerr << "Failed to fetch products: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_close(db);
    return 0;
}

int main() {
    return performDbOperations();
}
