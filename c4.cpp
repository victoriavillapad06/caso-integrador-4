//
// Created by victo on 15/12/2024.
//

#include "test1.h"

#include "../tiny-lisp/tinylisp.h"

void log_test(const std::string& test_name, bool success) {
    if (success) {
        std::cout << "[TEST PASSED] " << test_name << std::endl;
    } else {
        std::cout << "[TEST FAILED] " << test_name << std::endl;
    }
}

int run_tests () {
    setlocale(LC_ALL, "es_ES.UTF-8");

    try {
        std::cout << "¡Hola, mundo!" << std::endl;

        // Prueba 1: Crear un Variant List con dos símbolos y un número
        try {
            Variant sym1(Symbol, "hello");
            Variant sym2(Symbol, "world");
            Variant num(Number, "42");

            Variant lst(List);
            lst.list.push_back(sym1);
            lst.list.push_back(sym2);
            lst.list.push_back(num);

            log_test("Crear Variant List con dos símbolos y un número", true);
        } catch (const std::exception& e) {
            log_test("Crear Variant List con dos símbolos y un número", false);
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Prueba 2: Convertir a string
        try {
            Variant sym1(Symbol, "hello");
            Variant sym2(Symbol, "world");
            Variant num(Number, "42");

            Variant lst(List);
            lst.list.push_back(sym1);
            lst.list.push_back(sym2);
            lst.list.push_back(num);

            std::cout << "to_string: " << lst.to_string() << "\n";
            log_test("Convertir Variant List a string", true);
        } catch (const std::exception& e) {
            log_test("Convertir Variant List a string", false);
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Prueba 3: Convertir a JSON
        try {
            Variant sym1(Symbol, "hello");
            Variant sym2(Symbol, "world");
            Variant num(Number, "42");

            Variant lst(List);
            lst.list.push_back(sym1);
            lst.list.push_back(sym2);
            lst.list.push_back(num);

            std::string json_str = lst.to_json_string();
            std::cout << "to_json_string: " << json_str << "\n";
            log_test("Convertir Variant List a JSON", true);
        } catch (const std::exception& e) {
            log_test("Convertir Variant List a JSON", false);
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Prueba 4: Reconstruir desde JSON
        try {
            Variant sym1(Symbol, "hello");
            Variant sym2(Symbol, "world");
            Variant num(Number, "42");

            Variant lst(List);
            lst.list.push_back(sym1);
            lst.list.push_back(sym2);
            lst.list.push_back(num);

            std::string json_str = lst.to_json_string();
            Variant reconstructed = Variant::from_json_string(json_str);

            std::cout << "Reconstruido desde JSON: " << reconstructed.to_string() << "\n";
            log_test("Reconstruir Variant List desde JSON", true);
        } catch (const std::exception& e) {
            log_test("Reconstruir Variant List desde JSON", false);
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error fatal en el programa: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}