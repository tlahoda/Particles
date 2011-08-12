/**
 * \file Spring.h, Contains the Spring class.
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
#ifndef PARTICLE_SPRING_H
#define PARTICLE_SPRING_H

#include "particles/common.h"

namespace particle {
    /**
     * \class Spring, Models a spring force.
     */
    class Spring {
        public:
            /**
             * Constructs a zero length spring with no coefficent and no damping.
             */
            Spring ()
              : nominal_ (0.0f), k_ (0.0f), b_ (0.0f) {};

            /**
             * Constructs a spring of nominal length with a coefficient of k and a damping factor of b.
             *
             * \param nominal float, The at rest distance of the spring.
             * \param k float, The spring coefficient.
             * \param b float, The damping factor.
             */
            Spring (float nominal, float k, float b)
              : nominal_ (nominal), k_ (k), b_ (b) {};

            /**
             * Calculates the spring force of the connection.
             *
             * \tparam Connection, The type of the connection.
             *
             * \param conn Connection&, the connection for which to calculate the spring force.
             *
             * \return Vector, the spring force.
             */
            template<class Connection>
            Vector operator() (Connection& conn) const {
                Vector spring (3);
                spring = conn.second ().position () - conn.first ().position ();
                float distance = sqrt (pow (spring[0], 2.0f) + pow (spring[1], 2.0f) + pow (spring[2], 2.0f));
  
                Vector springNorm (3);
                springNorm = spring / distance;
  
                Vector deltaV = conn.second ().velocity () - conn.first ().velocity ();
                float springSpeed = springNorm[0] * deltaV[0] + springNorm[1] * deltaV[1] + springNorm[2] * deltaV[2];
  
                return springNorm * (-k_ * (distance - nominal_)) + springNorm * springSpeed * -b_;
            };

        private:
            /**
             * The at rest distance of the spring.
             */
            float nominal_;

            /**
             * The spring coefficient.
             */
            float k_;

            /**
             * The damping factor.
             */
            float b_;
    }; //Spring
}; //particle

#endif //PARTICLE_SPRING_H

