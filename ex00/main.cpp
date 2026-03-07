/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-h <lgomez-h@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:30:33 by lgomez-h          #+#    #+#             */
/*   Updated: 2025/07/01 18:37:25 by lgomez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

void test_vector() {
    std::cout << "=== Pruebas con std::vector ===" << std::endl;
    int arr[] = {1, 2, 3, 4, 5, 3, 2, 1};
    std::vector<int> vec(arr, arr + 8);

    // Buscar al principio
    try {
        std::vector<int>::iterator it = easyfind(vec, 1);
        std::cout << "Encontrado (principio): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (principio): " << e.what() << std::endl;
    }

    // Buscar en medio
    try {
        std::vector<int>::iterator it = easyfind(vec, 4);
        std::cout << "Encontrado (medio): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (medio): " << e.what() << std::endl;
    }

    // Buscar al final
    try {
        std::vector<int>::iterator it = easyfind(vec, 1);
        std::cout << "Encontrado (final): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (final): " << e.what() << std::endl;
    }

    // Buscar valor repetido
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Encontrado (repetido): " << *it << " (posición: " << (it - vec.begin()) << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (repetido): " << e.what() << std::endl;
    }

    // Buscar valor inexistente
    try {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "Encontrado (inexistente): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (inexistente): " << e.what() << std::endl;
    }

    // Vector vacío
    std::vector<int> empty_vec;
    try {
        std::vector<int>::iterator it = easyfind(empty_vec, 1);
        std::cout << "Encontrado (vacío): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (vacío): " << e.what() << std::endl;
    }
}

void test_list() {
    std::cout << "\n=== Pruebas con std::list ===" << std::endl;
    int arr[] = {10, 20, 30, 40, 50, 30, 20, 10};
    std::list<int> lst(arr, arr + 8);

    // Buscar al principio
    try {
        std::list<int>::iterator it = easyfind(lst, 10);
        std::cout << "Encontrado (principio): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (principio): " << e.what() << std::endl;
    }

    // Buscar en medio
    try {
        std::list<int>::iterator it = easyfind(lst, 40);
        std::cout << "Encontrado (medio): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (medio): " << e.what() << std::endl;
    }

    // Buscar valor repetido
    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Encontrado (repetido): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (repetido): " << e.what() << std::endl;
    }

    // Buscar valor inexistente
    try {
        std::list<int>::iterator it = easyfind(lst, 99);
        std::cout << "Encontrado (inexistente): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (inexistente): " << e.what() << std::endl;
    }

    // Lista vacía
    std::list<int> empty_lst;
    try {
        std::list<int>::iterator it = easyfind(empty_lst, 10);
        std::cout << "Encontrado (vacío): " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No encontrado (vacío): " << e.what() << std::endl;
    }
}

int main() {
    test_vector();
    test_list();
    return 0;
}
