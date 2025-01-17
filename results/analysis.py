#%%
import pandas as pd

#%%
columns = ["Expanded Nodes", "Solution Cost", "Total Time (s)", "Mean Heuristic", "Initial Heuristic"]

bfs_8p = pd.read_csv('bfs_8puzzle.csv', header=None, names=columns)
idfs_8p = pd.read_csv('idfs_8puzzle.csv', header=None, names=columns)
gbfs_8p = pd.read_csv('gbfs_8puzzle.csv', header=None, names=columns)
astar_8p = pd.read_csv('astar_8puzzle.csv', header=None, names=columns)
idastar_8p = pd.read_csv('idastar_8puzzle.csv', header=None, names=columns)
astar_lc_8p = pd.read_csv('astar_lc_8puzzle.csv', header=None, names=columns)

#%%
print(bfs_8p.to_latex(longtable=True, caption="BFS results for the 8-Puzzle"))
print(idfs_8p.to_latex(longtable=True, caption="IDFS results for the 8-Puzzle"))
print(gbfs_8p.to_latex(longtable=True, caption="GBFS results for the 8-Puzzle"))
print(idastar_8p.to_latex(longtable=True, caption="IDA* results for the 8-Puzzle"))
print(astar_8p.to_latex(longtable=True, caption="A* results for the 8-Puzzle"))
print(astar_lc_8p.to_latex(longtable=True, caption="A* with linear conflicts heuristic results for the 8-Puzzle"))

# %%
bfs_8p['Algorithm'] = 'BFS'
idfs_8p['Algorithm'] = 'IDFS'
gbfs_8p['Algorithm'] = 'GBFS'
astar_8p['Algorithm'] = 'A*'
astar_lc_8p['Algorithm'] = 'A* + LC'
idastar_8p['Algorithm'] = 'IDA*'
mean_df = pd.concat([bfs_8p, idfs_8p, gbfs_8p, astar_8p, astar_lc_8p, idastar_8p]).groupby('Algorithm').mean()
print(mean_df.to_latex(longtable=True, caption="Average results for the 8-Puzzle instances"))

# %%
astar_15p = pd.read_csv('astar_15puzzle.csv', header=None, names=columns, na_values='-')
astar_lc_15p = pd.read_csv('astar_lc_15puzzle.csv', header=None, names=columns, na_values='-')
print(astar_15p.to_latex(longtable=True, caption="A* results for the 15-Puzzle", na_rep='-'))
print(astar_lc_15p.to_latex(longtable=True, caption="A* with linear conflicts heuristic results for the 15-Puzzle", na_rep='-'))

astar_15p['Algorithm'] = 'A*'
astar_15p['Solved Instances'] = len(astar_15p[pd.notna(astar_15p['Solution Cost'])])
astar_lc_15p['Algorithm'] = 'A* + LC'
astar_lc_15p['Solved Instances'] = len(astar_lc_15p[pd.notna(astar_lc_15p['Solution Cost'])])

mean_df = pd.concat([astar_15p, astar_lc_15p]).groupby('Algorithm').mean()
print(mean_df.to_latex(longtable=True, caption="Average results for the 15-Puzzle instances"))