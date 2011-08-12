/**
 * \file VectorStorage.h, Contains the VectorStorage class.
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
#ifndef PARTICLE_VECTORSTORAGE_H
#define PARTICLE_VECTORSTORAGE_H

#include "boost/shared_array.hpp"

#include "sdlpp/misc/Position.h"

namespace particle {
    /**
     * \class VectorStorage, Vector storage for the particles.
     *
     * \tparam Particle, The type of the particles to store.
     */
    template<class Particle>
    class VectorStorage {
        public:
            /**
             * \typedef Particle particle,
             *          The type of the particle.
             */
            typedef Particle particle;

            /**
             * \typedef typename std::vector<Particle>::iterator iterator,
             *          The type of the iterator.
             */
            typedef typename std::vector<Particle>::iterator iterator;

            /**
             * Constructs a VectorStorage containing numParticles particles.
             *
             * \param numParticles unsigned int, The number of particles with which to construct the vector.
             */
            explicit VectorStorage (unsigned int numParticles)
              : vec_ (new std::vector<Particle> (numParticles)) {};

            /**
             * The start of the vector.
             *
             * \return typename VectorStorage<Particle>::iterator, The start of the vector.
             */
            iterator begin () { return vec_.get ()->begin (); };

            /**
             * The start of the vector.
             *
             * \return typename VectorStorage<Particle>::iterator, The start of the vector.
             */
            iterator begin () const { return vec_.get ()->begin (); };
            
            /**
             * The end of the vector.
             *
             * \return typename VectorStorage<Particle>::iterator, The end of the vector.
             */
            iterator end () { return vec_.get ()->end (); };
            
            /**
             * The end of the vector.
             *
             * \return typename VectorStorage<Particle>::iterator, The end of the vector.
             */
            iterator end () const { return vec_.get ()->end (); };

            /**
             * Adds a particle to the vector.
             *
             * \param particle const Particle&, The particle to add.
             *
             * \return VectorStorage<Particle>&, a reference to the VectorStorage object.
             */
            VectorStorage& add (const Particle& particle) {
                vec_.get ()->push_back (particle); 
                return *this;
            };

            /**
             * Returns the particle at index.
             *
             * \param index unsigned int, The index of the particle to return.
             *
             * \return Particle&, The particle.
             */
            Particle& operator[] (unsigned int index) { return vec_[index]; };

        private:
            /**
             * The vector in which to store the particles.
             */
            boost::shared_ptr<std::vector<Particle> > vec_;
    }; //VectorStorage
}; //particle

#endif //PARTICLE_VECTORSTORAGE_H

