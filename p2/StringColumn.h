//
// Created by kramt on 2/6/2020.
//

#pragma once

public class StringColumn : public Column() {

    public:
        /**
         * Creates a String Column from undetermined number of
         * String parameters.
         */
         StringColumn(String*... args);

        /**
          * Destructor
         */
          ~StringColumn();

        /**
         * Returns the String* to the SoR at the specified
         * index idx in this StringColumn
         */
          String* get_string(size_t idx);

};

