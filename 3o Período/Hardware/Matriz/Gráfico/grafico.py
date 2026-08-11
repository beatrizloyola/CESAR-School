import matplotlib.pyplot as plt

n = [64, 256, 1024, 2096]
razao = [1.091463415, 2.526908367, 3.883410678, 15.512683954]

plt.figure(figsize=(8, 5))
plt.plot(n, razao, marker='o', linewidth=2, markersize=6)

plt.xlabel('n')
plt.ylabel('Razão (coluna/linha)')
plt.title('Razão x n')
plt.grid(True)
plt.tight_layout()
plt.show()