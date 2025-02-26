# Discussion

## Solutions Considered

### 1. **Loading Entire File into Memory**
- **Approach:** Read the entire log file into memory, filter lines containing the target date, and write them to an output file.
- **Pros:** Simple and easy to implement.
- **Cons:** Not feasible for a 1TB file due to excessive memory usage and slow performance.

### 2. **Using Line-by-Line File Reading (Chosen Approach)**
- **Approach:** Read the log file **line by line**, check if a line starts with the target date, and write matching lines to an output file.
- **Pros:**
  - Memory-efficient (no need to load the entire file).
  - Fast filtering using `rfind(targetDate, 0) == 0`.
  - Works well with large files.
- **Cons:** Slightly slower than memory-based filtering for small files but scales well.

### 3. **Using Multi-threaded or Parallel Processing**
- **Approach:** Split the file into chunks, process them in parallel, and merge results.
- **Pros:** Faster processing for extremely large files.
- **Cons:** Complex implementation, potential I/O bottlenecks.

## Final Solution Summary

The final solution **reads the file line by line** and extracts logs starting with the given date. This approach was chosen because:
- **It minimizes memory usage**, making it suitable for a 1TB+ file.
- **It efficiently filters logs** using `rfind()`.
- **It is easy to implement and scales well** for large datasets.

## Steps to Run

### **1. Compile the C++ Program**
```sh
 g++ extract_logs.cpp -o extract_logs
```

### **2. Run the Program**
```sh
 ./extract_logs <log_file_path> <YYYY-MM-DD>
```
Example:
```sh
 ./extract_logs logs.txt 2024-12-01
```

### **3. Output Location**
- Extracted logs will be saved in the `output` directory as:
  ```
  output/output_YYYY-MM-DD.txt
  ```
- Example:
  ```
  output/output_2024-12-01.txt
  ```

### **4. Handling Large Files Efficiently**
- Ensure **sufficient disk space** for output logs.
- Use **SSD storage** for faster processing.
- Run the program in a **background process** if needed:
  ```sh
  nohup ./extract_logs logs.txt 2024-12-01 &
  ```

This solution balances **efficiency, simplicity, and scalability** for large log files.

