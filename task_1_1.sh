#!/bin/bash -l

#SBATCH -J task_1_1
#SBATCH -t 01:00:00
#SBATCH -A edu23.DD2356
#SBATCH -p main
#SBATCH -e error_file.e
#SBATCH -n 128

#SBATCH --ntasks-per-node=128
#SBATCH --cpus-per-task=1
#SBATCH --nodes=1

srun ./task_1_1.out > task_1_1.output
