#!/bin/bash
#Files taken from Daniel Gao
#./gen_large_sor.py
#./gen_med_sor.py

#SOURCE: https://stackoverflow.com/questions/54920113/calculate-average-execution-time-of-a-program-using-bash
avg_time() {
    #
    # usage: avg_time n command ...
    #
    n=$1; shift
    (($# > 0)) || return                   # bail if no command given
    for ((i = 0; i < n; i++)); do
        { time -p "$@" &>/dev/null; } 2>&1 # ignore the output of the command
                                           # but collect time's output in stdout
    done | awk '
        /real/ { real = real + $2; nr++ }
        /user/ { user = user + $2; nu++ }
        /sys/  { sys  = sys  + $2; ns++}
        END    {
                 if (nr>0) printf("real %f\n", real/nr);
                 if (nu>0) printf("user %f\n", user/nu);
                 if (ns>0) printf("sys %f\n",  sys/ns)
               }'
}

runNoArgs() {
	make $1
	echo "---------SMALL:"
	ps faux | grep casper
	avg_time 10 ./sorer -f ../small.sor
	echo "---------MEDIUM:"
	avg_time 10 ./sorer -f ../medium.sor
	echo "---------LARGE:"
	avg_time 10 ./sorer -f ../large.sor
}

runDiffArgs(){
	 make $2
	./sorer -f $1   -print_col_type 0

         ./sorer -f $1   -print_col_type 2

         ./sorer -f  $1  -is_missing_idx 2 0

         ./sorer -f $1   -is_missing_idx 2 1

         ./sorer -f $1   -is_missing_idx 2 2

         ./sorer -f $1   -print_col_idx 2 0

         ./sorer -f $1   -print_col_idx 1 0

         ./sorer -f $1   -print_col_type 0

         ./sorer -f $1   -print_col_type 2

         ./sorer -f $1   -print_col_type 1

         ./sorer -f $1   -print_col_type 3

         ./sorer -f $1   -print_col_type 0

         ./sorer -f $1   -print_col_idx 0 1

         ./sorer -f $1   -print_col_idx 2 2

         ./sorer -f $1   -print_col_idx 3 0

         ./sorer -f $1   -print_col_idx 1 2

         ./sorer -f $1   -print_col_idx 1 0

         ./sorer -f $1   -is_missing_idx 3 1

         ./sorer -f $1   -is_missing_idx 3 2

         ./sorer -f $1   -is_missing_idx 1 1

         ./sorer -f $1   -is_missing_idx 1 1

         ./sorer -f $1   -print_col_idx 2 0

         ./sorer -f $1   -print_col_idx 2 0

         ./sorer -f $1   -print_col_idx 3 0
}

runDAComp() {
	make $2
         ./sorer -f "$@"   -print_col_type 0
        make $2
         ./sorer -f "$@"   -print_col_type 2
        make $2
         ./sorer -f "$@"   -is_missing_idx 2 0
        make $2
         ./sorer -f "$@"   -is_missing_idx 2 1
        make $2
         ./sorer -f "$@"   -is_missing_idx 2 2
        make $2
         ./sorer -f "$@"   -print_col_idx 2 0
        make $2
         ./sorer -f "$@"   -print_col_idx 1 0
        make $2
         ./sorer -f "$@"   -print_col_type 0
        make $2
         ./sorer -f "$@"   -print_col_type 2
        make $2
         ./sorer -f "$@"   -print_col_type 1
        make $2
         ./sorer -f "$@"   -print_col_type 3
        make $2
         ./sorer -f "$@"   -print_col_type 0
        make $2
         ./sorer -f "$@"   -print_col_idx 0 1
        make $2
         ./sorer -f "$@"   -print_col_idx 2 2
        make $2
         ./sorer -f "$@"   -print_col_idx 3 0
        make $2
         ./sorer -f "$@"   -print_col_idx 1 2
        make $2
         ./sorer -f "$@"   -print_col_idx 1 0
        make $2
         ./sorer -f "$@"   -is_missing_idx 3 1
        make $2
         ./sorer -f "$@"   -is_missing_idx 3 2
        make $2
         ./sorer -f "$@"   -is_missing_idx 1 1
        make $2
         ./sorer -f "$@"   -is_missing_idx 1 1
        make $2
         ./sorer -f "$@"   -print_col_idx 2 0
        make $2
         ./sorer -f "$@"   -print_col_idx 2 0
        make $2
         ./sorer -f "$@"   -print_col_idx 3 0
}
	
#https://github.com/danielgaooooo/a1p1/blob/master/gen_large_sor.py
cd CS4500_Assignment3
#1 build, 1 run, 1 iteration
echo "===============================1 build, 1 run================================="
runNoArgs build

#1 build, multiple runs
echo "===============================1 build, multiple runs================================="
echo "---------SMALL:"
avg_time 10 runDiffArgs ../small.sor build
echo "---------MEDIUM:"
avg_time 10 runDiffArgs ../medium.sor build
echo "---------LARGE:"
avg_time 10 runDiffArgs ../large.sor build

#multiple builds, multiple runs, 1 iteration
echo "===============================multiple builds, multiple runs================================="
echo "---------SMALL:"
avg_time 10 runDAComp ../small.sor
echo "---------MEDIUM:"
avg_time 10 runDAComp ../medium.sor
echo "---------LARGE:"
avg_time 10 runDAComp ../large.sor
