"""
main_visualization_simplificado.py
Script principal simplificado para visualizar os resultados dos algoritmos de ordenação
"""

import os
import sys
import time
from visualization import create_all_visualizations

def main():
    """Função principal para visualizar os resultados"""
    print("=" * 60)
    print("VISUALIZAÇÃO DE ALGORITMOS DE ORDENAÇÃO")
    print("=" * 60)
    
    # Definir diretórios padrão
    results_dir = "../results"
    output_dir = "../visualizations"
    
    # Verificar argumentos de linha de comando
    if len(sys.argv) > 1:
        results_dir = sys.argv[1]
    if len(sys.argv) > 2:
        output_dir = sys.argv[2]
    
    print(f"\nDiretório de resultados: {results_dir}")
    print(f"Diretório de saída para visualizações: {output_dir}")
    
    # Verificar se o diretório de resultados existe
    if not os.path.exists(results_dir):
        print(f"\nErro: O diretório de resultados '{results_dir}' não existe.")
        print("Execute primeiro o código C para gerar os resultados.")
        return 1
    
    # Verificar se existem arquivos CSV no diretório de resultados
    csv_files = [f for f in os.listdir(results_dir) if f.endswith('.csv')]
    if not csv_files:
        print(f"\nErro: Nenhum arquivo CSV encontrado em '{results_dir}'.")
        print("Execute primeiro o código C para gerar os resultados.")
        return 1
    
    print(f"\nArquivos de resultados encontrados: {len(csv_files)}")
    for csv_file in sorted(csv_files):
        print(f"  - {csv_file}")
    
    # Medir o tempo de execução
    start_time = time.time()
    
    # Criar visualizações
    print("\nCriando visualizações...")
    create_all_visualizations(results_dir, output_dir)
    
    # Calcular tempo de execução
    execution_time = time.time() - start_time
    
    print(f"\nVisualização concluída em {execution_time:.2f} segundos.")
    print(f"Visualizações salvas em: {output_dir}")
    print("=" * 60)
    
    return 0

if __name__ == "__main__":
    sys.exit(main())