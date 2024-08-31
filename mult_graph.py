import pandas as pd
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("mult.csv")
df = df.groupby('n', as_index=False).mean()

columns_set1 = ['n' , 'time2', 'time6']
columns_set2 = ['n' ,'time1',  'time3']
columns_set3 = ['n' ,'time4', 'time5']

plt.figure()  
plt.plot(1, 3, 3)
df_temp = df[['n','time1','time2','time3','time4','time5','time6']]
df_temp.plot(x='n', linestyle='-', ax=plt.gca())
plt.xlabel('n')
plt.ylabel('Time')
plt.tight_layout()
plt.savefig(f'matrix_mult.png')
    
i = 1
for columns_set in [columns_set1, columns_set2,columns_set3]:
    df1 = df[columns_set]
    plt.figure()  
    plt.plot(1, 3, 3)
    df1.plot(x='n', linestyle='-', ax=plt.gca())
    plt.xlabel('n')
    plt.ylabel('Time')
    # Adjust layout to prevent overlapping titles
    plt.tight_layout()
    # Save the plot as an image
    plt.savefig(f'matrix_mult{i}.png')
    i+=1

