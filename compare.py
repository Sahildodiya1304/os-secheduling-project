import matplotlib.pyplot as plt

algorithms = []
values = []

# read comparison data
with open("comparison_data.txt") as f:
    for line in f:
        name, val = line.split()
        algorithms.append(name)
        values.append(float(val))

plt.figure(figsize=(8,5))

plt.barh(algorithms, values)

plt.xlabel("Average Waiting Time")
plt.ylabel("Algorithms")
plt.title("CPU Scheduling Algorithms Comparison")

# show value on bars
for i, v in enumerate(values):
    plt.text(v + 0.05, i, f"{v:.2f}")

plt.show()