import matplotlib.pyplot as plt

# Timing data
data = {
    "13": {"real": 0.02},
    "14": {"real": 0.04},
    "15": {"real": 0.09},
    "16": {"real": 0.17},
    "17": {"real": 0.35},
    "18": {"real": 0.69},
    "19": {"real": 1.39},
    "20": {"real": 2.78},
}

# Extract labels and times for each run
labels = list(data.keys())
real_times = [entry["real"] for entry in data.values()]

# Create a bar chart for real times
plt.figure(figsize=(10, 5))
plt.bar(labels, real_times, label="Real Time (s)", color='b', alpha=0.6)
plt.xlabel('Number of quantifiers')
plt.ylabel('Time (seconds)')
plt.title('Program Timing Data (Real Time)')
plt.legend(loc="upper right")

# Show the plot
plt.tight_layout()
plt.show()
