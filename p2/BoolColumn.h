//
// Created by kramt on 2/6/2020.
//

#pragma once

#include "stdarg.h"

public class BoolColumn : public Column {

        public:
        /**
         * Creates a Bool Column from number num of
         * Bool parameters.
         */
        BoolColumn(int num, ...);

        /**
          * Destructor
         */
        ~BoolColumn();

        /**
         * Returns the Bool* to the SoR at the specified
         * index idx in this BoolColumn
         */
        bool get_bool(size_t idx);

        /**
        * Adds Bool b to this BoolColumn at index idx.
        */
        void add_bool(bool b, size_t idx);

};

