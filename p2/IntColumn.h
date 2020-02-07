//
// Created by kramt on 2/6/2020.
//

#pragma once
#include "stdarg.h"

public class IntColumn : public Column {

public:
    /**
     * Creates a Int Column from number num of
     * Int parameters.
     */
    IntColumn(int num, ...);

    /**
      * Destructor
     */
    ~IntColumn();

    /**
     * Returns the int to the SoR at the specified
     * index idx in this IntColumn
     */
    int get_int(size_t idx);

    /**
     * Adds Int i to this IntColumn at index idx.
     */
     void add_int(int i, size_t idx);

};