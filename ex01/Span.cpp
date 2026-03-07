/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-h <lgomez-h@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:45:52 by lgomez-h          #+#    #+#             */
/*   Updated: 2025/07/01 18:51:51 by lgomez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize)
        throw std::runtime_error("No se pueden añadir más números");
    numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("No hay suficientes números para calcular el span");

    std::vector<int> tmp(numbers);
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 1; ++i) {
        int span = tmp[i + 1] - tmp[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("No hay suficientes números para calcular el span");

    std::vector<int>::const_iterator minIt = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(numbers.begin(), numbers.end());
    return *maxIt - *minIt;
}