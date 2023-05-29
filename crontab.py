import sched
import time
import subprocess

# Create a scheduler object
scheduler = sched.scheduler(time.time, time.sleep)

# Define the function to be executed
def execute_task():
    # Replace the command with the task you want to execute
    subprocess.call(["python", r"C:\Users\leine\OneDrive\Documentos\Visual Studio Code\Pruebas\py\CambioDivisas.py"])

# Define the schedule (in seconds)
schedule_interval = 300  # Execute the task every minute

# Define the main scheduling function
def schedule_task():
    # Execute the task
    execute_task()
    # Schedule the task to run again after the defined interval
    scheduler.enter(schedule_interval, 1, schedule_task)

# Start the scheduler
scheduler.enter(schedule_interval, 1, schedule_task)
scheduler.run()