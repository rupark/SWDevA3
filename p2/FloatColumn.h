//
// Created by kramt on 2/6/2020.
//

public class FloatColumn : public Column {
    public:
        /**
         * Creates a Float Column from number num of
         * Float parameters.
         */
        FloatColumn(int num, ...);

        /**
          * Destructor
         */
        ~FloatColumn();

        /**
         * Returns the Float* to the SoR at the specified
         * index idx in this FloatColumn
         */
        Float* get_float(size_t idx);

        /**
        * Adds Float f to this FloatColumn at index idx.
        */
        void add_float(float i, size_t idx);

};