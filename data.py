import subprocess
import pandas as pd
def compile_and_get_data(n):
    try:
        execute_command = f"./main {n} 1"
        process = subprocess.Popen(execute_command, stdout=subprocess.PIPE, shell=True)
        output, _ = process.communicate()
        
        # Decode the output bytes to a string
        return output.decode('utf-8')
    except:
        return


compile_command = "gcc -o main main.c"
subprocess.run(compile_command, shell=True, check=True)

with open("mult4.csv", "w") as f:
    # Write the header
    # f.write("n,inplace,extramemory\n")
    f.write("n,time1,time2,time3,time4,time5,time6\n")
    # Accumulate data in memory before writing to file
    
    # Iterate over the range of values
    for i in range(4090, 4100, 1):
        for j in range(0,2):
            f.write(compile_and_get_data(i))
            print(i,j)

    # Write accumulated data to file
        


