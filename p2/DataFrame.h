//
// Created by kramt on 2/6/2020.
//

// Design Decisions
// col_headers unqiue
// row_headers unique
// Able to make an empty dataframe
// able to remove a row... from all Columns
// Returns Columns


#pragma once
#include "BoolColumn.h"
#include "IntColumn.h"
#include "StringColumn.h"
#include "FloatColumn.h"
#include "Column.h"

public class DataFrame {

    public:

        /**
        * Accepts Columns to add to the DataFrame.
        */
        DataFrame(Column*...varargs);

        /**
        * Creates an empty DataFrame.
        */
        DataFrame();

        /**
        * Destructor.
        */
        ~DataFrame();

        /**
         * Returns whether the given Object contains equivalent
         * data to this DataFrame.
         */
        bool equals (Object* o);

        /**
        * Returns the hash of this DataFrame.
        */
        size_t hash();

        /**
         * Returns if this DataFrame has row names.
         */
        bool contains_row_names();

        /**
         * Returns if this DataFrame has column names.
         */
         bool contains_col_names();

         /**
          * Returns the number of rows in this DataFrame.
          */
         size_t nrow();

         /**
          * Returns the number of rows in the Column at
          * index idx of this DataFrame (in case of
          * uneven columns added).
          */
         size_t nrow(size_t idx);

         /**
          * Returns the number of Columns in this DataFrame.
          */
         size_t ncol();

         /**
          * Returns the hash of this DataFrame.
          */
         size_t hash();

         /**
          * Returns the SoR at the given row col of this DataFrame.
          */
         SoR get(size_t row, size_t col);

         /**
          * Returns the SoR at the corresponding row matching row header
          * and column matching col_header.
          */
          SoR get(char* row_header, char* col_header);

          /**
           * Deletes the row at the specified index idx from all
           * the Columns in this DataFrame.
           */
          void delete_row(size_t idx);

          // Delete Rows (char* row_header)
          /**
           * Deletes the row with the corresponding row_header
           * if found in this DataFrame (row_header will be unique).
           */
          void delete_row(char* row_header);

          /**
           * Deletes and returns the Column at the corresponding
           * index idx in this DataFrame.
           */
          Column delete_col(size_t idx);

          // Delete Col (char* col_header)
          /**
           * Deletes and returns the Column if found with the
           * corresponding Column Header (col_header will be unique).
           */
          Column delete_col(char* col_header);

          /**
           * Adds the Column to this DataFrame.
           */
           void add_col(Column* col);

          /**
           * Returns the Column at the specified index idx in this DataFrame.
           */
           Column get_col(size_t idx);

          /**
           * Returns the Column with the corresponding col_header in
           * this DataFrame (col_header is unique in DataFrame).
           */
           Column get_col(char* col_header);

         /**
          * Returns the index of the specified row header in
          * this DataFrame (row_header is unique in DataFrame).
          */
           size_t get_row_idx (char* row_header);
};