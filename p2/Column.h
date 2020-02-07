//
// Created by kramt on 2/6/2020.
//

/**
 * Base class for all Column Classes.
 */
public Column {

    public:

        /**
         * Returns the number of SoR in this Column.
         */
        size_t size();

        /**
         * Returns the header of this Column if existent.
         */
        char* get_header();

        /**
         * Adds header to the Column String* s.
         */
        void add_header(String* s);

        /**
         * Returns if this column contains a header.
         */
        bool contains_header();

        /**
         * Returns type of this Column.
         */
        virtual char* get_col_type();

        /**
        * Returns whether the Object* passed in contains equivalent.
        */
        virtual bool equals(Object* o);

        /**
         * Hash function for this Column.
         */
        virtual size_t hash();

        /**
         * Removes the SoR at the index idx
         */
        void remove(size_t idx);
};
