"""This file contains the AWS Lambda function to return the current time adjusted for a given timezone offset."""
import json
from datetime import datetime, timedelta

def lambda_handler(event: dict, context: dict) -> dict:
    """AWS Lambda function to return the current time adjusted for a given timezone offset.
    
    Args:
        event (dict): The event data passed to the Lambda function, which may include a "timezone_offset" key.
        context (dict): The context in which the Lambda function is called (not used in this function).
    Returns:
        dict: A response containing the adjusted time in hours and minutes, and the timezone offset used.
    
    """

    # Get timezone offset from event (default = 0 if not provided)
    timezone_offset = int(event.get("timezone_offset", 0))
    
    # Get current UTC time
    now_utc = datetime.utcnow()
    
    # Apply timezone offset
    adjusted_time = now_utc + timedelta(hours=timezone_offset)
    
    # Extract zero-padded minutes
    minutes = adjusted_time.strftime("%M")
    hours = adjusted_time.strftime("%H")
    
    return {
        "statusCode": 200,
        "body": json.dumps({
            "minutes": minutes,
            "hours": hours,
            "timezone_offset": timezone_offset
        })
    }
