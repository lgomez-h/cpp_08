/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-h <lgomez-h@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:50:03 by lgomez-h          #+#    #+#             */
/*   Updated: 2025/07/01 18:50:08 by lgomez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
    try {
        // Prueba básica con 5 números
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

        // Prueba de excepción al añadir más de la capacidad
        try {
            sp.addNumber(42);
        } catch (const std::exception& e) {
            std::cout << "Excepción esperada: " << e.what() << std::endl;
        }

        // Prueba con addNumbers usando un vector grande
        Span bigSpan(10000);
        std::vector<int> bigVec;
        for (int i = 0; i < 10000; ++i)
            bigVec.push_back(i * 2);

        bigSpan.addNumbers(bigVec.begin(), bigVec.end());
        std::cout << "bigSpan shortestSpan: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "bigSpan longestSpan: " << bigSpan.longestSpan() << std::endl;

        // Prueba de excepción con menos de dos números
        Span emptySpan(2);
        emptySpan.addNumber(1);
        try {
            emptySpan.shortestSpan();
        } catch (const std::exception& e) {
            std::cout << "Excepción esperada: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Excepción inesperada: " << e.what() << std::endl;
    }
    return 0;
}