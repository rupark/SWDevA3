//
// Created by kramt on 2/6/2020.
//

#pragma once

public class IntColumn : public Column {

public:
    /**
     * Creates a Int Column from undetermined number of
     * Int parameters.
     */
    IntColumn(Int*... args);

    /**
      * Destructor
     */
    ~IntColumn();

    /**
     * Returns the Int* to the SoR at the specified
     * index idx in this IntColumn
     */
    Int* get_int(size_t idx);

    /**
     * Adds Int i to this IntColumn at index idx.
     */
     void add_int(Int* i, size_t idx);

};