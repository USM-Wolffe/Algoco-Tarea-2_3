import pandas as pd
import matplotlib.pyplot as plt

# Cargar los datos desde la carpeta /data
data = pd.read_csv('resultados.csv')  

# Preparar las columnas relevantes
data['length_s1'] = data['s1'].str.len()
data['length_s2'] = data['s2'].str.len()

# Clasificar los casos
data['case'] = data.apply(
    lambda row: 's1 > s2' if row['length_s1'] > row['length_s2']
    else 's2 > s1' if row['length_s2'] > row['length_s1']
    else 's1 = s2',
    axis=1
)

# Asegurarse de que la columna de tiempo esté en formato numérico
data['time_us'] = data['Tiempo (μs)']

# Filtrar datos incongruentes
data = data[data['time_us'] > 0]

# Crear gráficos individuales para cada caso
cases = data['case'].unique()
for case in cases:
    case_data = data[data['case'] == case]
    
    plt.figure(figsize=(10, 6))
    
    # Graficar datos por algoritmo
    for algorithm in case_data['Algoritmo'].unique():
        algo_data = case_data[case_data['Algoritmo'] == algorithm]
        plt.plot(
            algo_data.index,
            algo_data['time_us'],
            label=algorithm
        )
    
    # Títulos y etiquetas
    plt.title(f'Tiempo de Ejecución por Algoritmo: {case}', fontsize=14)
    plt.xlabel('Índice de las Pruebas', fontsize=12)
    plt.ylabel('Tiempo de Ejecución (μs)', fontsize=12)
    plt.legend(title='Algoritmo', fontsize=10)
    plt.grid(True)
    plt.show()

datat= pd.read_csv('resultados-T.csv')
# Asegurarse de que las columnas necesarias estén en el formato correcto
datat['Categoria'] = datat['Categoria'].astype(str)  # Categoría como cadena
datat['Algoritmo'] = datat['Algoritmo'].astype(str)  # Algoritmo como cadena
datat['Tiempo (μs)'] = pd.to_numeric(datat['Tiempo (μs)'], errors='coerce')  # Tiempo como numérico

# Resumir datos para el gráfico
summary = datat.groupby(['Categoria', 'Algoritmo']).agg({
    'Tiempo (μs)': ['mean', 'median', 'std']
}).reset_index()

# Ajustar nombres de columnas
summary.columns = ['Categoria', 'Algoritmo', 'Tiempo Promedio (μs)', 'Tiempo Mediano (μs)', 'Desviación Estándar (μs)']

# Preparar datos para gráfico de barras
summary_pivot = summary.pivot(index='Categoria', columns='Algoritmo', values='Tiempo Promedio (μs)')

# Crear gráfico de barras
summary_pivot.plot(kind='bar', figsize=(10, 6))
plt.title('Tiempo Promedio por Categoría y Algoritmo', fontsize=14)
plt.ylabel('Tiempo Promedio (μs)', fontsize=12)
plt.xlabel('Categoría', fontsize=12)
plt.xticks(rotation=0)
plt.legend(title='Algoritmo', fontsize=10)
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.show()