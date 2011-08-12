/**
 * \file Constraint.h, Contains the Constraint class.
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
#ifndef PARTICLE_CONSTRAINT_H
#define PARTICLE_CONSTRAINT_H

#include "particles/common.h"

namespace particle {
    /**
     * \class Constraint, Constrains the particles of a connections.
     */
    template<class Connection>
    class Constraint {
        public:
            /**
             * Constructs a Constraint for a Connection.
             *
             * \param const Connection& connection, The Connection to constrain
             */
            Constraint (const Connection& connection)
                : connection_ (connection) {};

            /**
             * Excercises the Constraint.
             *
             * \return void.
             */
            virtual void operator() () = 0;

            /**
             * Returns the constrained Connection.
             *
             * \return Connection&, A reference to the Connection.
             */
            Connection& connection () { return connection_; };

        protected:
            /**
             * The constrained Connection.
             */
            Connection connection_; 
    }; //Constraint
}; //particle

#endif //PARTICLE_CONSTRAINT_H

