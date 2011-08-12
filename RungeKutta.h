/**
 * \file RungeKutta.h, Contains the RungeKutta class.
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
#ifndef PARTICLE_RUNGEKUTTA_H
#define PARTICLE_RUNGEKUTTA_H

#include "particles/common.h"

namespace particle {
    /**
     * \class RungeKutta, Calculates the position and velocity of a particle using Runge-Kutta integration.
     */
    class RungeKutta {
        public:
            /**
             * Constructs a RungeKutta using the given delta T.
             *
             * \param dt float, The delta T to use.
             */
            explicit RungeKutta (float dt)
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
             * Calculates the position and velocity of a particle using Runge-Kutta integration.
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
                Vector v_k1 = acceleration * dt_;
                Vector v_k2 = acceleration + v_k1 * 0.5f * dt_;
                Vector v_k3 = acceleration + v_k2 * 0.5f * dt_;
                Vector v_k4 = acceleration + v_k3 * dt_;
                 
                Vector& velocity = particle.velocity ();
                Vector x_k1 = velocity * dt_;
                Vector x_k2 = velocity + x_k1 * 0.5f * dt_;
                Vector x_k3 = velocity + x_k2 * 0.5f * dt_;
                Vector x_k4 = velocity + x_k3 * dt_;
                
                Vector& position = particle.position ();
                velocity += (v_k1 + v_k2 * 2.0f + v_k3 * 2.0f + v_k4) / 6.0f * dt_;
                position += (x_k1 + x_k2 * 2.0f + x_k3 * 2.0f + x_k4) / 6.0f * dt_;
            };

        private:
            /**
             * The delta T.
             */
            float dt_;
    }; //RungeKutta
}; //particle

#endif //PARTICLE_RUNGEKUTTA_H

