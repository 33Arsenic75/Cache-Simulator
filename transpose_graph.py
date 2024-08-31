import pandas as pd
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("transpose.csv")
df = pd.concat([df1, df2, df3])
# df = pd.read_csv("transpose.csv")
df = df.groupby('n', as_index=False).mean()

# columns_set1 = ['n' , 'time2', 'time6']

# columns_set2 = ['n' ,'time1',  'time3', 'time4', 'time5']
y_min = df.drop('n', axis=1).min().min()  # Minimum value across all columns excluding 'n'
y_max = df.drop('n', axis=1).max().max()  # Maximum value across all columns excluding 'n'

# Calculate a padding factor to give some space above and below the data
padding_factor = 1  # Adjust this as needed
y_range = y_max - y_min
y_padding = y_range * padding_factor

print(y_min, y_max)
# Set the new y-axis limits
plt.gca().set_ylim(y_min - y_padding, y_max + y_padding)

# Continue with your plotting code
plt.figure()
plt.plot(1, 3, 3)
df.plot(x='n', linestyle='-', ax=plt.gca())
plt.xlabel('n')
plt.ylabel('Time')
plt.tight_layout()
plt.savefig(f'matrix_tranpose.png')


