#!/bin/bash
#SBATCH -N 1
#SBATCH --ntasks-per-node 4
#SBATCH -t 00:03:00
#SBATCH -p normal_q
#SBATCH -A node7

# Submit this file as a job request with
# sbatch submission.sh

# Change to the directory from which the job was submitted
cd $SLURM_SUBMIT_DIR

# Unload all except default modules
module reset

# Load the modules you need
module load gcc

# Compile (this may not be necessary if the program is already built)
gcc -o montecarlopi.out montecarlopi.c -fopenmp -lm 

# Print the number of threads for future reference
echo "Running montecarlopi"

# Run the program. Don't forget arguments!
./montecarlopi.out 2
./montecarlopi.out 3
./montecarlopi.out 4
./montecarlopi.out 5
./montecarlopi.out 6

# The script will exit whether we give the "exit" command or not.
exit
