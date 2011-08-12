/**
 * \file Particle.h, Contains the Particle class.
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
#ifndef PARTICLE_PARTICLE_H
#define PARTICLE_PARTICLE_H

#include <vector>
#include <cstdlib>

#include <boost/numeric/ublas/vector.hpp>

#include "particles/common.h"

#include "particles/Constraint.h"
#include "particles/Connection.h"

namespace particle {
    /**
     * \class Particle, Models a particle.
     */
    class Particle
    {
        public:
            /**
             * \typedef std::vector<Connection<Constraint, Particle>*>::iterator iterator,
             *          The type of the iterator.
             */
            typedef std::vector<Constraint<Connection<Particle> >*>::iterator iterator;

            /**
             * Constructs a particle at the origin.
             */
            Particle ()
              : position_ (make_Vector (0.0f, 0.0f, 0.0f)),
                oldPosition_ (make_Vector (0.0f, 0.0f, 0.0f)),
                velocity_ (make_Vector (0.0f, 0.0f, 0.0f)),
                force_ (make_Vector (0.0f, 0.0f, 0.0f)),
                mass_ (0.1f),
                pinned_ (false),
                constraints_ () {};

            /**
             * Constructs a particle at position.
             *
             * \param position const Vector&, The position at which to construct the particle.
             */
            explicit Particle (const Vector& pos)
              : position_ (position),
                oldPosition_ (position),
                velocity_ (make_Vector (0.0f, 0.0f, 0.0f)),
                force_ (make_Vector (0.0f, 0.0f, 0.0f)),
                mass_ (0.1f),
                pinned_ (false),
                constraints_ () {};

            /**
             * The current position of the particle.
             *
             * \return Vector&, The current position of the particle.
             */
            Vector& position () { return position_; };

            /**
             * The current position of the particle.
             *
             * \return Vector, The current position of the particle.
             */
            Vector position () const { return position_; };

            /**
             * The last position of the particle.
             *
             * \return Vector&, The last position of the particle.
             */
            Vector& oldPosition () { return oldPosition_; };
            
            /**
             * The last position of the particle.
             *
             * \return Vector, The last position of the particle.
             */
            Vector oldPosition () const { return oldPosition_; };

            /**
             * The current velocity of the particle.
             *
             * \return Vector&, The current velocity of the particle.
             */
            Vector& velocity () { return velocity_; };
            
            /**
             * The current velocity of the particle.
             *
             * \return Vector, The current velocity of the particle.
             */
            Vector velocity () const { return velocity_; };

            /**
             * The current force on the particle.
             *
             * \return Vector&, The current force on the particle.
             */
            Vector& force () { return force_; };
            
            /**
             * The current force on the particle.
             *
             * \return Vector, The current force on the particle.
             */
            Vector force () const { return force_; };

            /**
             * The mass of the particle.
             *
             * \return float&, The mass of the particle.
             */
            float& mass () { return mass_; };
            
            /**
             * The mass of the particle.
             *
             * \return float, The mass of the particle.
             */
            float mass () const { return mass_; };

            /**
             * Whether or not the particle can move.
             *
             * \return bool&, Whether or not the particle can move.
             */
            bool& pinned () { return pinned_; };
            
            /**
             * Whether or not the particle can move.
             *
             * \return bool, Whether or not the particle can move.
             */
            bool pinned () const { return pinned_; };

            /**
             * The connections directly acting on the particle.
             *
             * \return std::vector<Connection<Constraint, Particle>*>&, The connections directly acting on the particle.
             */
            std::vector<Constraint<Connection<Particle> >*>& constraints () { return constraints_; };
   
        private:
            /**
             * The current position of the particle.
             */
            Vector position_;

            /**
             * The last position of the particle.
             */
            Vector oldPosition_;

            /**
             * The current velocity of the particle.
             */
            Vector velocity_;

            /**
             * The current force of the particle.
             */
            Vector force_;

            /**
             * The mass of the particle.
             */
            float mass_;

            /**
             * Whether or not the particle can move.
             */
            bool pinned_;

            /**
             * The connections directly acting on the particle.
             */
            std::vector<Constraint<Connection<Particle> >*> constraints_;
    }; //Particle
}; //particle

#endif //PARTICLE_PARTICLE_H

