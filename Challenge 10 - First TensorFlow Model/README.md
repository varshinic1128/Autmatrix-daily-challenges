# Day 10 – First TensorFlow Model

## Project Overview

This project demonstrates how to build and train a simple neural network using TensorFlow to learn the mathematical relationship:

**y = 2x**

The model is trained using sample input and output values and is then used to predict new values. The predicted values are compared with the actual values to understand how well the model has learned the relationship.

## Objective

- Create a simple dataset based on y = 2x.
- Build a small neural network using TensorFlow.
- Train the model using sample data.
- Make predictions using the trained model.
- Compare predicted values with actual values.
- Visualize the predictions against the actual values.

## Technologies Used

- Python
- TensorFlow
- NumPy
- Matplotlib
- Google Colab / Python

## Dataset

The model uses simple input-output pairs following the relationship:

```python
y = 2 * x
```

The input values are used to generate corresponding output values. These pairs form the training dataset for the neural network.

## Working

1. Create sample input values and their corresponding outputs.
2. Build a simple neural network using TensorFlow and Keras.
3. Compile the model with an optimizer and loss function.
4. Train the model using the dataset.
5. Predict outputs for new input values.
6. Compare the predicted values with the actual values.
7. Visualize the results using Matplotlib.

## Expected Output

The trained model should learn the relationship y = 2x and predict values close to twice the given input.

A graph is used to compare the actual values with the model's predictions.

## Learning Outcome

- Understand the basics of neural networks.
- Learn how to create and train a TensorFlow model.
- Understand model prediction and evaluation.
- Visualize actual and predicted values.

## Project Status

Completed
