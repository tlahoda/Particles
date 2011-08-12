/**
 * \file Euler.h, Contains the Euler class.
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
#ifndef PARTICLE_EULER_H
#define PARTICLE_EULER_H

#include "particles/common.h"

namespace particle {
    /**
     * \class Euler, Calculates the position and velocity of a particle using Euler integration.
     */
    class Euler {
        public:
            /**
             * Constructs a Euler using the given delta T.
             *
             * \param dt float, The delta T to use.
             */
            explicit Euler (float dt)
              : dt_ (dt) {};

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
             * Calculates the position and velocity of a particle using Euler integration.
             *
             * \tparam Particle, The type of the particle.
             *
             * \param particle Particle&, The particle for which to calculate the position and velocity.
             *
             * \return void.
             */
            template<class Particle>
            void operator() (Particle& particle) const {
                Vector acceleration = particle.force () / particle.mass ();
                Vector& velocity = particle.velocity ();
                velocity += acceleration * dt_;

                //Vector& position = particle.position ();
                //position += velocity * dt_ + acceleration * dt_ * dt_ / 2.0f;
                particle.position () += velocity * dt_ + acceleration * dt_ * dt_ / 2.0f;
            };

        private:
            /**
             * The delta T.
             */
            float dt_;
    }; //Euler
}; //particle

#endif //PARTICLE_EULER_H

