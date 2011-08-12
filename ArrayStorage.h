/**
 * \file ArrayStorage.h, Contains the ArrayStorage class.
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
#ifndef PARTICLE_ARRAYSTORAGE_H
#define PARTICLE_ARRAYSTORAGE_H

#include "boost/shared_array.hpp"

#include "sdlpp/misc/Position.h"

namespace particle {
    /**
     * \class ArrayStorage, Array storage for the particles.
     *
     * \tparam Particle, The type of the particles to store.
     */
    template<class Particle>
    class ArrayStorage {
        public:
            /**
             * \typedef Particle particle.
             *          The type of the particle to store..
             */
            typedef Particle particle;

            /**
             * \typedef Particle* iterator,
             *          The type of the particle iterator.
             */
            typedef Particle* iterator;

            /**
             * Constructs an ArrayStorage containing numParticles particles.
             *
             * \param numParticles unsigned int, The number of particles to construct the array with.
             */
            explicit ArrayStorage (unsigned int numParticles)
                : array_ (new Particle[numParticles]), size_ (numParticles) {};

            /**
             * The start of the ArrayStorage.
             *
             * \return typename ArrayStorage<Particle>::iterator, The start of the ArrayStorage.
             */
            iterator begin () { return &array_.get ()[0]; };

            /**
             * The start of the ArrayStorage.
             *
             * \return typename ArrayStorage<Particle>::iterator, The start of the ArrayStorage.
             */
            iterator begin () const { return &array_.get ()[0]; };

            /**
             * The end of the ArrayStorage.
             *
             * \return typename ArrayStorage<Particle>::iterator, The end of the ArrayStorage.
             */
            iterator end () { return &array_.get ()[size_]; };

            /**
             * The end of the ArrayStorage.
             *
             * \return typename ArrayStorage<Particle>::iterator, The end of the ArrayStorage.
             */
            iterator end () const { return &array_.get ()[size_] };

            Particle& operator[] (unsigned int index) {
                return array_[index];
            };

        private:
            /**
             * The array in which to store the particles.
             */
            boost::shared_array<Particle> array_;

            /**
             * The size of the array.
             */
            unsigned int size_;
    }; //ArrayStorage
}; //particle

#endif //PARTICLE_ARRAYSTORAGE_H

