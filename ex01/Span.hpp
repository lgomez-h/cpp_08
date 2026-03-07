/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-h <lgomez-h@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:44:39 by lgomez-h          #+#    #+#             */
/*   Updated: 2025/07/01 18:48:55 by lgomez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
public:
    Span(unsigned int N);
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    
    template<typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end);

private:
    std::vector<int> numbers; // Almacena los números
    unsigned int maxSize; // Tamaño máximo permitido
};
template<typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end) {
    for (InputIterator it = begin; it != end; ++it) {
        if (numbers.size() >= maxSize)
            throw std::runtime_error("No se pueden añadir más números");
        numbers.push_back(*it);
    }
}
#endif
