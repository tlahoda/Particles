/**
 * \file Grid.h, Contains the Grid class.
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
#ifndef PARTICLE_GRID_H
#define PARTICLE_GRID_H

#include <boost/thread/mutex.hpp>

#include "particles/common.h"

namespace particle {
    /**
     * \class Grid, Aligns the particles in a grid.
     *
     * \param Storage, The type of the storage.
     */
    template<class Storage>
    class Grid {
        public:
            /**
             * \typedef typename Storage::particle particle,
             *          The type of particle..
             */
            typedef typename Storage::particle particle;

            /**
             * \typedef typename Storage::iterator iterator,
             *          The type of iterator.
             */
            typedef typename Storage::iterator iterator;
	   
            /**
             * Constructs a Grid.
             *
             * \param origin const Vector&, The origin.
             * \param height float, The height.
             * \param width float, The width.
             * \param verticalSpacing float, The vertical spacing.
             * \param horizontalSpacing float, The horizontal spacing.
             */
            Grid (const Vector& origin, float height, float width, float verticalSpacing, float horizontalSpacing)
              : origin_ (origin),
                s_ (int (height * width)),
                height_ (height),
                width_ (width),
                verticalSpacing_ (verticalSpacing),
                horizontalSpacing_ (horizontalSpacing) {

                iterator curIter = s_.begin ();

                for (float i = 0; i < int (height_); ++i) {
                    for (float j = 0; j < int (width_); ++j) {
                        curIter->position () = make_Vector ((float (j) - width_ / 2.0f) * horizontalSpacing,
                                                            (height_ - float (i) - height_ / 2.0f + 2.0f) * verticalSpacing,
                                                            0.0f);
                        curIter->oldPosition () = curIter->position ();
                        ++curIter;
                    }
                }
            };

            /**
             * Returns the beginning of the particles.
             *
             * \return iterator, The beginning of the particles.
             */
            iterator begin () { return s_.begin (); };

            /**
             * Returns the end of the particles.
             *
             * \return iterator, The end of the particles.
             */
            iterator end () { return s_.end (); };

            /**
             * Returns the height.
             *
             * \return float, The height.
             */
            float height () { return height_; };
            
            /**
             * Returns the width.
             *
             * \return float, The width.
             */
            float width () { return width_; };

            /**
             * Returns the origin.
             *
             * \return Vector&, The origin.
             */
            Vector& origin () { return origin_; };
            
            /**
             * Returns the origin.
             *
             * \return Vector&, The origin.
             */
            Vector& origin () const { return origin_; };

            /**
             * Returns the vertical spacing of the particles.
             *
             * \return float&, The veritcal spacing.
             */
            float& verticalSpacing () { return verticalSpacing_; };
            
            /**
             * Returns the horizontal spacing of the particles.
             *
             * \return float&, The horizontal spacing.
             */
            float& horizontalSpacing () { return horizontalSpacing_; };

        private:
            /**
             * The origin.
             */
            Vector origin_;

            /**
             * The particle storage.
             */
            Storage s_;

            /**
             * The height.
             */
            float height_;

            /**
             * The width.
             */
            float width_;

            /**
             * The vertical spacing of the particles.
             */
            float verticalSpacing_;

            /**
             * The horizontal spacing of the particles.
             */
            float horizontalSpacing_;
    }; //Grid
}; //particle

#endif //PARTICLE_GRID_H

