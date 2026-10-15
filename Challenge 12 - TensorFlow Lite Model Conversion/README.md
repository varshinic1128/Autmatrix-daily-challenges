# Day 12 – TensorFlow Lite Model Conversion

## Project Overview

This project demonstrates the conversion of a trained TensorFlow neural network into a lightweight TensorFlow Lite (`.tflite`) model.

A small neural network is trained to classify light-level readings into three categories: Dark, Normal, and Bright.

After training, the model is converted into TensorFlow Lite format using `TFLiteConverter`. The converted model is then loaded using the TensorFlow Lite Interpreter and tested with sample light-level readings.

The predictions from the original TensorFlow model and the converted TFLite model are compared to verify inference parity.

## Objective

- Create a small labeled light-level dataset.
- Train a dense neural network using TensorFlow.
- Classify light readings as Dark, Normal, or Bright.
- Convert the trained TensorFlow model into `.tflite` format.
- Load the converted TFLite model.
- Run inference using the TFLite model.
- Compare TensorFlow and TFLite predictions.
- Verify that both models produce the same predictions.

## Technologies Used

- Python
- TensorFlow
- TensorFlow Lite
- NumPy
- Google Colab

## Light-Level Categories

| Light Reading | Category |
|---|---|
| Low light readings | Dark |
| Medium light readings | Normal |
| High light readings | Bright |

The model uses normalized light readings based on a 12-bit ADC range of 0–4095.

## Dataset

The project uses sample light-level readings with three classes.

| Light Reading | Class |
|---:|---|
| 100 | Dark |
| 300 | Dark |
| 500 | Dark |
| 700 | Dark |
| 1000 | Normal |
| 1300 | Normal |
| 1600 | Normal |
| 2000 | Normal |
| 2500 | Bright |
| 3000 | Bright |
| 3500 | Bright |
| 4000 | Bright |

## Model Architecture

The project uses a small dense neural network.

```text
Input Layer
     ↓
Dense Layer – 16 neurons – ReLU
     ↓
Dense Layer – 8 neurons – ReLU
     ↓
Output Layer – 3 neurons – Softmax
```

## Working

1. Create and label the light-level dataset.
2. Normalize the input readings.
3. Build and train a dense neural network using TensorFlow.
4. Convert the trained model into TensorFlow Lite format.
5. Load the `.tflite` model using the TensorFlow Lite Interpreter.
6. Run predictions using both TensorFlow and TensorFlow Lite.
7. Compare the predicted classes to check whether the converted model produces matching results.

## Expected Output

The model classifies light-level readings into Dark, Normal, or Bright categories.

The TensorFlow and TensorFlow Lite predictions are compared to verify that model conversion preserves the prediction results.

## Learning Outcomes

- Understand TensorFlow Lite model conversion.
- Learn how to build and train a neural network.
- Understand input normalization and classification.
- Perform inference using the TensorFlow Lite Interpreter.
- Compare predictions before and after model conversion.

## Challenge Status

Completed
