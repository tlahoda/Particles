/**
 * \file Verlet.h, Contains the Verlet class.
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
#ifndef PARTICLE_VERLET_H
#define PARTICLE_VERLET_H

#include "particles/common.h"

namespace particle {
    /**
     * \class Verlet, Calculates the position and velocity of a particle using Verlet integration.
     *
     * \tparam Correction, The type of the ocrrection to do.
     */
    template<class Correction>
    class Verlet {
        public:
            /**
             * Constructs a Verlet using the given delta T.
             *
             * \param dt float, The delta T to use.
             * \param correction const Correction&, The correction to apply.
             */
            Verlet (float deltaT, const Correction& correction)
              : dt_ (deltaT ()), correction_ (correction) {};

            /**
             * The delta T.
             *
             * \return float&, The delta T.
             */
            float& dt () { return dt_; };

            /**
             * The delta T.
             *
             * \return float, The delta T.
             */
            float dt () const { return dt_; };

            /**
             * Calculates the position and velocity of a particle using Verlet integration.
             *
             * \tparam Particle, The type of the particle.
             *
             * \param particle Particle&, Tthe particle for which to calculate the position and velocity.
             *
             * \return void.
             */
            template<class Particle>
            void operator() (Particle& particle) const {
                Vector curPosition = particle.position ();
                Vector& position = particle.position ();
                Vector& oldPosition = particle.oldPosition ();
                Vector& velocity = particle.velocity ();
 
                if (!particle.pinned ())
                    position += position - oldPosition + particle.force () / particle.mass () * dt_ * dt_;
                correction_ (particle);
                velocity = (position - oldPosition) / (2.0f * dt_);
                oldPosition = curPosition;
            };

        private:
            /**
             * The delta T.
             */
            float dt_;
            
            /**
             * The correction functor.
             */
            Correction correction_;
    }; //Verlet
}; //particle

#endif //PARTICLE_VERLET_H

