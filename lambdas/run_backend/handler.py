import json
import os
import boto3

# AWS clients
lambda_client = boto3.client("lambda")
iot_client = boto3.client("iot-data")

# Environment variables (recommended instead of hardcoding)
GET_TIME_FUNCTION = os.environ.get("GET_TIME_FUNCTION", "get_time")
INBOUND_TOPIC = os.environ.get("INBOUND_TOPIC", "arduino/inbound")


def lambda_handler(event, context):
    """
    Triggered by AWS IoT Core rule when a message is received
    on topic: arduino/outgoing
    """

    # Extract timezone offset from incoming MQTT message
    timezone_offset = event.get("timezone_offset", 0)

    # Invoke get_time Lambda
    response = lambda_client.invoke(
        FunctionName=GET_TIME_FUNCTION,
        InvocationType="RequestResponse",
        Payload=json.dumps({
            "timezone_offset": timezone_offset
        })
    )

    # Read payload from get_time response
    payload = json.loads(response["Payload"].read())

    # Publish result to MQTT topic
    iot_client.publish(
        topic=INBOUND_TOPIC,
        qos=1,
        payload=json.dumps(payload)
    )

    return {
        "status": "success",
        "published_to": INBOUND_TOPIC,
        "data": payload
    }
