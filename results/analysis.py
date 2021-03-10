#%%
import pandas as pd

#%%
columns = ["Expanded Nodes", "Solution Cost", "Total Time (s)", "Mean Heuristic", "Initial Heuristic"]

bfs_8p = pd.read_csv('bfs_8puzzle.csv', header=None, names=columns)
idfs_8p = pd.read_csv('idfs_8puzzle.csv', header=None, names=columns)
#gbfs_8p = pd.read_csv('gbfs_8puzzle.csv', header=None, names=columns)
#astar_8p = pd.read_csv('astar_8puzzle.csv', header=None, names=columns)
idastar_8p = pd.read_csv('idastar_8puzzle.csv', header=None, names=columns)

#%%
print(bfs_8p.to_latex(longtable=True, caption="BFS results for the 8-Puzzle"))
print(idfs_8p.to_latex(longtable=True, caption="IDFS results for the 8-Puzzle"))
#print(gbfs_8p.to_latex(longtable=True, caption="GBFS results for the 8-Puzzle"))
#print(astar_8p.to_latex(longtable=True, caption="A* results for the 8-Puzzle"))
print(idastar_8p.to_latex(longtable=True, caption="IDA* results for the 8-Puzzle"))

# %%
bfs_8p['Algorithm'] = 'BFS'
idfs_8p['Algorithm'] = 'IDFS'
#gbfs_8p['Algorithm] = 'GBFS'
#astar_8p['Algorithm] = 'A*'
idastar_8p['Algorithm'] = 'IDA*'
mean_df = pd.concat([bfs_8p, idfs_8p, idastar_8p]).groupby('Algorithm').mean()
print(mean_df.to_latex(longtable=True, caption="Average results for the 8-Puzzle instances"))

# %%
