//
// Created by kramt on 2/6/2020.
//

#pragma once

public class StringColumn : public Column() {

    public:
        /**
         * Creates a String Column from number num of
         * String parameters.
         */
         StringColumn(int num, ...);

        /**
          * Destructor
         */
          ~StringColumn();

        /**
         * Returns the String* to the SoR at the specified
         * index idx in this StringColumn
         */
          String* get_string(size_t idx);

        /**
         * Adds String s to this StringColumn at index idx.
         */
          void add_string(String* s, size_t idx);

};

