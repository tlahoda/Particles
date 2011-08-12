/**
 * \file DisplacementConstraint.h, Contains the DisplacementConstraint class.
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
#ifndef PARTICLE_DISPLACEMENTCONSTRAINT_H
#define PARTICLE_DISPLACEMENTCONSTRAINT_H

#include "particles/common.h"
#include "particles/Constraint.h"

namespace particle {
    /**
     * \class DisplacementConstraint, Constrains the particles of a connection to the nominal distance.
     *
     * \tparam Connection, The type of Connection to constrain.
     */
    template<class Connection>
    class DisplacementConstraint : public Constraint<Connection> {
        public:
            /**
             * Constructs a DisplacementConstraint.
             *
             * \param const Connection& connection, The Connection to constrain.
             */
            DisplacementConstraint (const Connection& connection)
              : Constraint<Connection> (connection), nominal_ (0.0f) {};

            /**
             * Constructs a DisplacementConstraint.
             *
             * \param const Connection& connection, The Connection to constrain.
             *
             * \param nominal float, The distance to which to constrain the particles.
             */
            explicit DisplacementConstraint (const Connection& connection, float nominal)
              : Constraint<Connection> (connection), nominal_ (nominal) {};

            /**
             * Move both of the particles to satisfy the distance constraint.
             *
             * \return void.
             */
            virtual void operator() ()
                Vector direction = Constraint<Connection>::connection_.second ().position () - Constraint<Connection>::connection_.first ().position ();
                float distance = sqrt (pow (direction[0], 2.0f) + pow (direction[1], 2.0f) + pow (direction[2], 2.0f));
                direction *= 0.5f * (distance - nominal_);
                if (distance != 0.0f) direction /= distance;
                if (!Constraint<Connection>::connection_.first ().pinned ()) Constraint<Connection>::connection_.first ().position () += direction;
                if (!Constraint<Connection>::connection_.second ().pinned ()) Constraint<Connection>::connection_.second ().position () -= direction;
            };

        private:
            /**
             * The distance to which to constrain the particles.
             */
            float nominal_;
    }; //DisplacementConstraint
}; //particle

#endif //PARTICLE_DISPLACEMENTCONSTRAINT_H

