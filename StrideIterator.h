/**
 * \file StrideIterator.h, Contains the StrideIterator class.
 *
 * Copyright (C) 2005 Thomas P. Lahoda
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef PARTICLE_STRIDEITERATOR_H
#define PARTICLE_STRIDEITERATOR_H

namespace particle {
    /**
     * \class StrideIterator, Iterates over a group of particles using the given stride.
     *
     * \tparam Container, The typ of the container over which to iterate.
     */
    template<class Container>
    class StrideIterator {
        public:
            /**
             * Constructs a StrideIterator using the given iterator and stride.
             *
             * \param iter const typename Container::iterator&, The initial iterator.
             * \param stride int, The stride.
             */
            StrideIterator (const typename Container::iterator& iter, int stride)
              : iter_ (iter), stride_ (stride) {};

            /**
             * Compares two StrideIterator.
             *
             * \param rhs const StrideIterator&, The StrideIterator to which to compare.
             *
             * \return bool, true if not equal.
             */
            bool operator!= (const StrideIterator& rhs) { return iter_ != rhs.iter_; };

            /**
             * The contained particle.
             *
             * \return typename Container::particle&, The contained particle.
             */
            typename Container::particle& operator* () { return *iter_; };
            
            /**
             * The contained particle.
             *
             * \return typename Container::particle*, The contained particle.
             */
            typename Container::particle* operator-> () { return iter_; };

            /**
             * Gets the underlying iterator.
             *
             * \return typename Container::iterator, The underlying iterator.
             */
            typename Container::iterator getIter () { return iter_; };

            /**
             * Increments the StrideIterator by the given amount.
             *
             * \param increment int, The amount to increment the StrideIterator.
             *
             * \return StrideIterator, The incremented StrideIterator.
             */
            StrideIterator operator+ (int increment) {
                StrideIterator temp = *this; 
                iter_ += increment * stride_; 
                return temp; 
            };
            
            /**
             * Pre-increment the StrideIterator.
             *
             * \return StrideIterator&, A reference to the incremented StrideIterator.
             */
            StrideIterator& operator++ () {
                iter_ += stride_; 
                return *this; 
            };

            /**
             * Post-increment the StrideIterator.
             *
             * \param dummy int, A dummy argument for the overloading of pre and post increment.
             *
             * \return StrideIterator, A reference to the incremented StrideIterator.
             */
            StrideIterator operator++ (int dummy) {
                StrideIterator temp = *this; 
                iter_ += stride_; 
                return temp; 
            };

        private:
            /**
             * The current particle.
             */
            typename Container::iterator iter_;

            /**
             * The stride of the iteration.
             */
            int stride_;
    }; //StrideIterator
}; //particle

#endif //PARTICLE_STRIDEITERATOR_H

