import pandas as pd

def find_constant(df, col1, col2):
    # Check if the columns exist in the DataFrame
    if col1 not in df.columns or col2 not in df.columns:
        raise ValueError("One or both of the columns do not exist in the DataFrame")
    
    # Ensure that the values are numeric
    if not pd.api.types.is_numeric_dtype(df[col1]) or not pd.api.types.is_numeric_dtype(df[col2]):
        raise ValueError("Both columns must contain numeric values")
    
    # Calculate the constant of proportionality
    ratios = df[col2] / df[col1]**2
    constant = ratios.mean()
    
    return constant

# df = pd.read_csv("mult.csv")
# df = df.groupby('n', as_index=False).mean()
# df = df[(df['n'] >= 200)]

# print(f"Constant time 1 {find_constant(df, 'n', 'time1')}")
# print(f"Constant time 2 {find_constant(df, 'n', 'time2')}")
# print(f"Constant time 3 {find_constant(df, 'n', 'time3')}")
# print(f"Constant time 4 {find_constant(df, 'n', 'time4')}")
# print(f"Constant time 5 {find_constant(df, 'n', 'time5')}")
# print(f"Constant time 6 {find_constant(df, 'n', 'time6')}")

df1 = pd.read_csv("transpose1.csv")
df2 = pd.read_csv("transpose2.csv")
df3 = pd.read_csv("transpose3.csv")
df = pd.concat([df1, df2, df3])
# df = pd.read_csv("transpose.csv")
df = df.groupby('n', as_index=False).mean()
df1 = df[(df['n'] <= 4096) & (df['n'] >= 200)]
df2 = df[df['n'] > 4096]

print(f"Constant time 1 {find_constant(df1, 'n', 'inplace')}")
print(f"Constant time 2 {find_constant(df1, 'n', 'extramemory')}")
print(f"Constant time 1 {find_constant(df2, 'n', 'inplace')}")
print(f"Constant time 2 {find_constant(df2, 'n', 'extramemory')}")
