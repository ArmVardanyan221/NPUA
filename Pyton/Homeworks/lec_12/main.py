import random
import time

def measure_time(func):
    def wrapper(*args, **kwargs):
        start_time = time.time() 
        result = func(*args, **kwargs)
        end_time = time.time()  
        print(f"Function {func.__name__} executed in {end_time - start_time:.6f} seconds.")
        return result
    return wrapper

@measure_time
def create_file(file_name):
    with open(file_name, 'w') as file:
        for _ in range(100):
            line = ' '.join(str(random.randint(0, 100)) for _ in range(20))  
            file.write(line + '\n')

@measure_time
def process_file(file_name):
    with open(file_name, 'r') as file:
        lines = file.readlines()
        processed_lines = []
        
        for line in lines:
            numbers = list(map(int, line.split())) 
            filtered_numbers = list(filter(lambda x: x > 40, numbers))  
            processed_lines.append(filtered_numbers)
        
    return processed_lines


@measure_time
def write_filtered_data(file_name, processed_lines):
    with open(file_name, 'w') as file:
        for line in processed_lines:
            file.write(' '.join(str(num) for num in line) + '\n')


def read_file_as_generator(file_name):
    with open(file_name, 'r') as file:
        for line in file:
            yield list(map(int, line.split())) 

@measure_time
def print_file(file_name):
  for line in read_file_as_generator(file_name):
    print(line)

    
file_name = "random_numbers.txt"

create_file(file_name)
    
processed_lines = process_file(file_name)
    
write_filtered_data(file_name, processed_lines)
    
print_file(file_name)
