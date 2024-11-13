import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Cargar datos desde el archivo CSV
data = pd.read_csv('resultados_experimento.csv')

# Función logarítmica para el ajuste
def log_function(n, a, b):
    return a * np.log(n) + b


for escenario in range(1, 5):

  data_escenario = data[data['Escenario'] == escenario]

  # Variables para el gráfico N vs Tiempo promedio por operación en Splay Tree
  data_escenario['Tiempo Promedio ABB'] = data_escenario['Tiempo ABB (ns)'] / data_escenario['M']  # Tiempo promedio por operación
  data_escenario['Tiempo Promedio Splay'] = data_escenario['Tiempo Splay Tree (ns)'] / data_escenario['M']  # Tiempo promedio por operación


  N_values = data_escenario['N'].values
  tiempo_promedio_abb = data_escenario['Tiempo Promedio ABB'].values
  tiempo_promedio_splay = data_escenario['Tiempo Promedio Splay'].values

  # Ajuste de curva logarítmica
  params, _ = curve_fit(log_function, N_values, tiempo_promedio_splay)
  a, b = params

  # Crear los valores de ajuste para la gráfica
  N_fit = np.linspace(min(N_values), max(N_values), 100)
  splay_fit = log_function(N_fit, a, b)

  # Gráfico de N vs Tiempo promedio por operación en Splay Tree
  plt.figure(figsize=(10, 6))
  plt.plot(N_values, tiempo_promedio_abb, 'o', label='Datos promedio ABB', markersize=5)
  plt.plot(N_values, tiempo_promedio_splay, 'o', label='Datos promedio Splay Tree', markersize=5)
  plt.plot(N_fit, splay_fit, '-', label=f'Ajuste logarítmico: $T(n) = {a:.3e} \cdot \log(n) + {b:.3e}$')
  plt.xlabel('N (tamaño del problema)')
  plt.ylabel('Tiempo promedio por operación (ns)')
  plt.title('Costo promedio por operación Splay Tree vs ABB')
  plt.legend()
  plt.grid()
  plt.show()
