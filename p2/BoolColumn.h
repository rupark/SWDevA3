//
// Created by kramt on 2/6/2020.
//

#pragma once

public class BoolColumn : public Column {

        public:
        /**
         * Creates a Bool Column from undetermined number of
         * Bool parameters.
         */
        BoolColumn(Bool*... args);

        /**
          * Destructor
         */
        ~BoolColumn();

        /**
         * Returns the Bool* to the SoR at the specified
         * index idx in this BoolColumn
         */
        Bool* get_bool(size_t idx);

        /**
        * Adds Bool b to this BoolColumn at index idx.
        */
        void add_bool(Bool* b, size_t idx);

};

