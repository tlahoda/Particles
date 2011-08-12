/**
 * \file Group.h, Contains the Group class.
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
#ifndef PARTICLE_GROUP_H
#define PARTICLE_GROUP_H

#include "boost/shared_array.hpp"

#include "particles/common.h"

namespace particle {
    /**
     * \class Group, A group of particles.
     *
     * \tparam Storage, The type of the storage mechanism.
     */
    template<class Storage>
    class Group {
        public:
            /**
             * \typedef typename Storage::particle particle,
             *          The particle type.
             */
            typedef typename Storage::particle particle;

            /**
             * \typedef typename Storage::iterator iterator,
             *          The iterator type.
             */
            typedef typename Storage::iterator iterator;

            /**
             * Constructs a group of particles with numParticles particles at the given origin.
             *
             * \param origin const Vector&, The origin of the particles.
             * \param numParticles unsigned int, The number of particlesin the group.
             */
            Group (const Vector& origin, unsigned int numParticles)
              : origin_ (origin), s_ (numParticles) {};

            /**
             * The first particle.
             *
             * \return typename Group<Storage>::iterator, An iterator to the first particle.
             */
            iterator begin () { return s_.begin (); };
            
            /**
             * The first particle.
             *
             * \return typename Group<Storage>::iterator, An iterator to the first particle.
             */
            iterator begin () const { return s_.begin (); };
            
            /**
             * One past the last particle.
             *
             * \return typename Group<Storage>::iterator, An iterator to one past the last particle.
             */
            iterator end () { return s_.end (); };
            
            /**
             * One past the last particle.
             *
             * \return typename Group<Storage>::iterator, An iterator to one past the last particle.
             */
            iterator end () const { return s_.end (); };

            /**
             * The origin of the particles.
             *
             * \return Vector&, The origin of the particles.
             */
            Vector& origin () { return origin_; };
            
            /**
             * The origin of the particles.
             *
             * \return Vector, The origin of the particles.
             */
            Vector origin () const { return origin_; };

            /**
             * Return the particle at index.
             *
             * \param index unsigned int, The particle to return.
             *
             * \return particle&, A reference to the particle.
             */
            particle& operator[] (unsigned int index) { return s_[index]; };

        private:
            /**
             * The origin of the group.
             */
            Vector origin_;

            /**
             * The particle storage.
             */
            Storage s_;
    }; //Group
}; //particle

#endif //PARTICLE_GROUP_H

