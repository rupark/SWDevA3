# Project: Assignment 3 #

## Authors: ##

Mark Thekkethala 

Kate Rupar

### Description: ###

DataFrame is the collection of type Columns.
The Column type has four subtypes which corresponds
to the four SoR types. StringColumn, BoolColumn,
IntColumn, and FloatColumn are derived classes 
of the Column class type. 

Each Column could potentially have a column header. 
The DataFrame also could potentially have row headers which
would be implemented with the first column added in the DataFrame.
This Row Header Column would store the row headers for each row.

There are multiple ways to populate this DataFrame. The Columns first
have to be filled using the constructor with a variable number of arguments.
After, each Column can be added to at specific index in the Column. There is 
also an ability to remove the object at the specified index in the Column using
the remove method. There is also an ability to get the particular type of object
from the particular type of Column. Each subtype of Column
will override the hash and equals methods.

The DataFrame uses the Column functionality to be able to
get the data from the DataFrame using a row, col index or the 
potential row header and col header. It also has the ability
to get the number of rows in a specific Column and the number of 
Columns in the DataFrame. You can add Columns to the DataFrame by 
passing in the Column or remove the Column using the index or the 
Column header. You can also delete a row from the DataFrame using the 
Column remove functionality to in essence remove the row's index or row
header to remove from every Column in the DataFrame.

Both DataFrame and Columns are able to check for equality to another object
and each define their hash methods.

### Use Cases: ###

Constructing a column of String SoR type

```
StringColumn* cars = new StringColumn(3, "Camry", "Corolla", "RAV4");
```

Adding a header to the cars column

```
cars.add_header("Row Header");
```

Constructing another column of String SoR type

```
StringColumn* manufacturer = new StringColumn(3, "Toyota", "Toyota", "Toyota");
```

Adding a header to the manufacturer column

```
manufacturer.add_header("Manufacturer");
```

Constructing a column of Float SoR type and adding a header

```
FloatColumn mpg = new FloatColumn(3, 22.2, 29.7, 33.4);
mpg.add_header("mpg");
```

Constructing a column of Bool SoR type and adding a header**

```
BoolColumn fwd = new BoolColumn(3, 0,0,1);
fwd.add_header("Four-Wheel Drive");
```

Constructing a column of Int SoR type and adding a header**

```
IntColumn year = new IntColumn(3, 2000, 2010, 2006);
fwd.add_header("Year");
```

Constructing a DataFrame with the created columns

```
DataFrame* cars = new DataFrame(4, cars, manufacturer, mpg, fwd, year);
```

Examples of retrieving data and manipulating data in the DataFrame

```
cars.get(1,1) ==> "Toyota";

cars.contains_col_names() = true;

cars.contains_row_names() = true;

cars.get("Camry", "mpg") ==> 22.2;

cars.nrow() ==> 3;

cars.ncol() ==> 4;

cars.delete_col("mpg");

cars.ncol() ==> 3;

cars.get("Corolla", "mpg") ==>

cars.add(mpg);

cars.get("Corolla","mpg") ==> 29.7

cars.delete_row("Camry");

cars.nrow() ==> 2;

cars.get("Camry", "Four-Wheel Drive") ==> 

cars.add(mpg); ==> will not work because "Camry" row has been deleted
```
