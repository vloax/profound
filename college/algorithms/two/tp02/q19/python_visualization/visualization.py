"""
visualization_expandido.py
Código expandido para visualizar os resultados dos algoritmos de ordenação
"""

import os
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from matplotlib.gridspec import GridSpec

# Definir estilo para os gráficos
plt.style.use('seaborn-v0_8-darkgrid')
sns.set_palette("colorblind")

def load_results(results_dir):
    """Carrega os resultados dos testes a partir do diretório de resultados"""
    try:
        # Tenta carregar o arquivo de resultados combinados
        combined_results_path = os.path.join(results_dir, "combined_results.csv")
        combined_df = pd.read_csv(combined_results_path)
        
        print(f"Resultados carregados com sucesso do arquivo: {combined_results_path}")
        print(f"Tamanhos testados: {combined_df['size'].values}")
        
        return combined_df
    except FileNotFoundError:
        print(f"Erro: Arquivo de resultados não encontrado em {results_dir}")
        print("Certifique-se de executar os testes em C primeiro para gerar os resultados.")
        exit(1)

def plot_execution_times(df, output_dir):
    """Plota gráfico de tempo de execução (linhas)"""
    fig, ax = plt.subplots(figsize=(10, 6))
    
    # Lista de algoritmos
    algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort', 'quick_sort']
    
    # Preparar dados
    sizes = df['size'].values
    
    # Gráfico de linhas simples
    for algorithm in algorithms:
        col_name = f"{algorithm}_execution_time_s"
        values = df[col_name].values
        # Substitui valores infinitos por NaN para exibição
        values = np.where(np.isinf(values), np.nan, values)
        ax.plot(sizes, values, marker='o', linewidth=2, label=algorithm.replace('_', ' ').title())
    
    ax.set_title('Tempo de Execução vs. Tamanho do Array')
    ax.set_xlabel('Tamanho do Array')
    ax.set_ylabel('Tempo de Execução (segundos)')
    ax.legend()
    ax.grid(True)
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, 'tempo_execucao.png'), dpi=300, bbox_inches='tight')
    print(f"Gráfico de tempo de execução salvo em {output_dir}/tempo_execucao.png")
    plt.close(fig)

def plot_individual_execution_times(df, output_dir):
    """Plota gráficos individuais de tempo de execução para cada algoritmo"""
    # Lista de algoritmos
    algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort', 'quick_sort']
    
    # Preparar dados
    sizes = df['size'].values
    
    # Criar diretório para gráficos individuais se não existir
    individual_dir = os.path.join(output_dir, "individuais")
    if not os.path.exists(individual_dir):
        os.makedirs(individual_dir)
    
    # Criar um gráfico para cada algoritmo
    for algorithm in algorithms:
        fig, ax = plt.subplots(figsize=(8, 5))
        
        col_name = f"{algorithm}_execution_time_s"
        values = df[col_name].values
        # Substitui valores infinitos por NaN para exibição
        values = np.where(np.isinf(values), np.nan, values)
        
        ax.plot(sizes, values, marker='o', linewidth=2, color='blue')
        
        # Adicionar valores nos pontos
        for i, (x, y) in enumerate(zip(sizes, values)):
            if not np.isnan(y):
                ax.annotate(f"{y:.4f}s", (x, y), 
                           textcoords="offset points", 
                           xytext=(0,10), 
                           ha='center')
        
        ax.set_title(f'Tempo de Execução: {algorithm.replace("_", " ").title()}')
        ax.set_xlabel('Tamanho do Array')
        ax.set_ylabel('Tempo de Execução (segundos)')
        ax.grid(True)
        
        plt.tight_layout()
        plt.savefig(os.path.join(individual_dir, f'tempo_{algorithm}.png'), dpi=300, bbox_inches='tight')
        print(f"Gráfico individual de tempo para {algorithm} salvo em {individual_dir}/tempo_{algorithm}.png")
        plt.close(fig)

def plot_comparisons(df, output_dir):
    """Plota gráfico de número de comparações (linhas)"""
    fig, ax = plt.subplots(figsize=(10, 6))
    
    # Lista de algoritmos
    algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort', 'quick_sort']
    
    # Preparar dados
    sizes = df['size'].values
    
    # Gráfico de linhas simples
    for algorithm in algorithms:
        col_name = f"{algorithm}_comparisons"
        ax.plot(sizes, df[col_name].values, marker='o', linewidth=2, label=algorithm.replace('_', ' ').title())
    
    ax.set_title('Número de Comparações vs. Tamanho do Array')
    ax.set_xlabel('Tamanho do Array')
    ax.set_ylabel('Número de Comparações')
    ax.legend()
    ax.grid(True)
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, 'comparacoes.png'), dpi=300, bbox_inches='tight')
    print(f"Gráfico de comparações salvo em {output_dir}/comparacoes.png")
    plt.close(fig)

def plot_individual_comparisons(df, output_dir):
    """Plota gráficos individuais de comparações para cada algoritmo"""
    # Lista de algoritmos
    algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort', 'quick_sort']
    
    # Preparar dados
    sizes = df['size'].values
    
    # Criar diretório para gráficos individuais se não existir
    individual_dir = os.path.join(output_dir, "individuais")
    if not os.path.exists(individual_dir):
        os.makedirs(individual_dir)
    
    # Criar um gráfico para cada algoritmo
    for algorithm in algorithms:
        fig, ax = plt.subplots(figsize=(8, 5))
        
        col_name = f"{algorithm}_comparisons"
        values = df[col_name].values
        
        ax.plot(sizes, values, marker='o', linewidth=2, color='green')
        
        # Adicionar valores nos pontos (formatados para melhor legibilidade)
        for i, (x, y) in enumerate(zip(sizes, values)):
            value_text = f"{int(y):,}".replace(',', '.')
            ax.annotate(value_text, (x, y), 
                       textcoords="offset points", 
                       xytext=(0,10), 
                       ha='center')
        
        ax.set_title(f'Comparações: {algorithm.replace("_", " ").title()}')
        ax.set_xlabel('Tamanho do Array')
        ax.set_ylabel('Número de Comparações')
        ax.grid(True)
        
        plt.tight_layout()
        plt.savefig(os.path.join(individual_dir, f'comparacoes_{algorithm}.png'), dpi=300, bbox_inches='tight')
        print(f"Gráfico individual de comparações para {algorithm} salvo em {individual_dir}/comparacoes_{algorithm}.png")
        plt.close(fig)

def plot_movements(df, output_dir):
    """Plota gráfico de número de movimentações (linhas)"""
    fig, ax = plt.subplots(figsize=(10, 6))
    
    # Lista de algoritmos
    algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort', 'quick_sort']
    
    # Preparar dados
    sizes = df['size'].values
    
    # Gráfico de linhas simples
    for algorithm in algorithms:
        col_name = f"{algorithm}_movements"
        ax.plot(sizes, df[col_name].values, marker='o', linewidth=2, label=algorithm.replace('_', ' ').title())
    
    ax.set_title('Número de Movimentações vs. Tamanho do Array')
    ax.set_xlabel('Tamanho do Array')
    ax.set_ylabel('Número de Movimentações')
    ax.legend()
    ax.grid(True)
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, 'movimentacoes.png'), dpi=300, bbox_inches='tight')
    print(f"Gráfico de movimentações salvo em {output_dir}/movimentacoes.png")
    plt.close(fig)

def plot_individual_movements(df, output_dir):
    """Plota gráficos individuais de movimentações para cada algoritmo"""
    # Lista de algoritmos
    algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort', 'quick_sort']
    
    # Preparar dados
    sizes = df['size'].values
    
    # Criar diretório para gráficos individuais se não existir
    individual_dir = os.path.join(output_dir, "individuais")
    if not os.path.exists(individual_dir):
        os.makedirs(individual_dir)
    
    # Criar um gráfico para cada algoritmo
    for algorithm in algorithms:
        fig, ax = plt.subplots(figsize=(8, 5))
        
        col_name = f"{algorithm}_movements"
        values = df[col_name].values
        
        ax.plot(sizes, values, marker='o', linewidth=2, color='red')
        
        # Adicionar valores nos pontos (formatados para melhor legibilidade)
        for i, (x, y) in enumerate(zip(sizes, values)):
            value_text = f"{int(y):,}".replace(',', '.')
            ax.annotate(value_text, (x, y), 
                       textcoords="offset points", 
                       xytext=(0,10), 
                       ha='center')
        
        ax.set_title(f'Movimentações: {algorithm.replace("_", " ").title()}')
        ax.set_xlabel('Tamanho do Array')
        ax.set_ylabel('Número de Movimentações')
        ax.grid(True)
        
        plt.tight_layout()
        plt.savefig(os.path.join(individual_dir, f'movimentacoes_{algorithm}.png'), dpi=300, bbox_inches='tight')
        print(f"Gráfico individual de movimentações para {algorithm} salvo em {individual_dir}/movimentacoes_{algorithm}.png")
        plt.close(fig)

def plot_combined_metrics(df, output_dir):
    """Plota gráficos que combinam todas as métricas para cada algoritmo"""
    # Lista de algoritmos
    algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort', 'quick_sort']
    
    # Preparar dados
    sizes = df['size'].values
    
    # Criar diretório para gráficos individuais se não existir
    individual_dir = os.path.join(output_dir, "individuais")
    if not os.path.exists(individual_dir):
        os.makedirs(individual_dir)
    
    # Criar um gráfico para cada algoritmo
    for algorithm in algorithms:
        fig, ax = plt.subplots(figsize=(10, 6))
        
        # Obter dados
        time_col = f"{algorithm}_execution_time_s"
        comp_col = f"{algorithm}_comparisons"
        move_col = f"{algorithm}_movements"
        
        time_values = df[time_col].values
        # Substitui valores infinitos por NaN para exibição
        time_values = np.where(np.isinf(time_values), np.nan, time_values)
        comp_values = df[comp_col].values
        move_values = df[move_col].values
        
        # Normalizar valores para escala [0,1] para permitir comparação
        # Tempo
        if not np.isnan(time_values).all():
            max_time = np.nanmax(time_values)
            if max_time > 0:
                norm_time_values = time_values / max_time
            else:
                norm_time_values = time_values
        else:
            norm_time_values = np.zeros_like(time_values)
        
        # Comparações
        max_comp = np.max(comp_values)
        if max_comp > 0:
            norm_comp_values = comp_values / max_comp
        else:
            norm_comp_values = comp_values
            
        # Movimentações
        max_move = np.max(move_values)
        if max_move > 0:
            norm_move_values = move_values / max_move
        else:
            norm_move_values = move_values
        
        # Plotar linhas normalizadas
        ax.plot(sizes, norm_time_values, marker='o', linewidth=2, color='blue', label='Tempo de Execução')
        ax.plot(sizes, norm_comp_values, marker='s', linewidth=2, color='green', label='Comparações')
        ax.plot(sizes, norm_move_values, marker='^', linewidth=2, color='red', label='Movimentações')
        
        # Configurar eixo Y secundário para exibir valores reais
        ax_time = ax.twinx()
        ax_time.spines['right'].set_position(('outward', 60))  # Move a segunda escala para fora
        ax_time.set_ylabel('Tempo (segundos)', color='blue')
        ax_time.plot(sizes, time_values, 'o', alpha=0)  # Invisível, apenas para escala
        ax_time.tick_params(axis='y', labelcolor='blue')
        
        ax_comp = ax.twinx()
        ax_comp.spines['right'].set_position(('outward', 120))  # Move a terceira escala mais para fora
        ax_comp.set_ylabel('Número de Comparações', color='green')
        ax_comp.plot(sizes, comp_values, 's', alpha=0)  # Invisível, apenas para escala
        ax_comp.tick_params(axis='y', labelcolor='green')
        
        ax_move = ax.twinx()
        ax_move.set_ylabel('Número de Movimentações', color='red')
        ax_move.plot(sizes, move_values, '^', alpha=0)  # Invisível, apenas para escala
        ax_move.tick_params(axis='y', labelcolor='red')
        
        # Configurar o gráfico principal
        ax.set_title(f'Métricas Comparativas: {algorithm.replace("_", " ").title()}')
        ax.set_xlabel('Tamanho do Array')
        ax.set_ylabel('Valores Normalizados [0,1]')
        ax.legend(loc='upper left')
        ax.grid(True)
        
        # Adicionar anotações nas curvas
        for i, (x, y_time, y_comp, y_move) in enumerate(zip(sizes, norm_time_values, norm_comp_values, norm_move_values)):
            if not np.isnan(y_time):
                ax.annotate(f"{time_values[i]:.4f}s", (x, y_time), 
                            textcoords="offset points", 
                            xytext=(0, 10), 
                            ha='center', fontsize=8)
            
            ax.annotate(f"{int(comp_values[i]):,}".replace(',', '.'), (x, y_comp), 
                        textcoords="offset points", 
                        xytext=(0, 10), 
                        ha='center', fontsize=8)
            
            ax.annotate(f"{int(move_values[i]):,}".replace(',', '.'), (x, y_move), 
                        textcoords="offset points", 
                        xytext=(0, 10), 
                        ha='center', fontsize=8)
        
        plt.tight_layout()
        plt.savefig(os.path.join(individual_dir, f'metricas_combinadas_{algorithm}.png'), dpi=300, bbox_inches='tight')
        print(f"Gráfico de métricas combinadas para {algorithm} salvo em {individual_dir}/metricas_combinadas_{algorithm}.png")
        plt.close(fig)

def plot_bars_comparison(df, output_dir):
    """Plota gráficos de barras para cada tamanho de array"""
    # Lista de algoritmos
    algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort', 'quick_sort']
    algorithm_names = [algo.replace('_', ' ').title() for algo in algorithms]
    
    # Para cada tamanho, criar um gráfico de barras
    for size in df['size'].values:
        # Filtrar dados para o tamanho atual
        size_data = df[df['size'] == size]
        
        fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(18, 6))
        
        # 1. Tempo de execução
        times = []
        for algorithm in algorithms:
            col_name = f"{algorithm}_execution_time_s"
            value = size_data[col_name].values[0]
            # Substituir infinito por NaN
            times.append(float('nan') if np.isinf(value) else value)
        
        bars1 = ax1.bar(algorithm_names, times, color=sns.color_palette("colorblind"))
        ax1.set_title(f'Tempo de Execução (Tamanho {size})')
        ax1.set_ylabel('Tempo (segundos)')
        
        # Adicionar valores nas barras
        for bar in bars1:
            height = bar.get_height()
            if not np.isnan(height):
                ax1.text(bar.get_x() + bar.get_width()/2., height + height*0.05,
                        f"{height:.4f}s", ha='center', va='bottom', rotation=0)
        
        # 2. Comparações
        comps = []
        for algorithm in algorithms:
            col_name = f"{algorithm}_comparisons"
            comps.append(size_data[col_name].values[0])
        
        bars2 = ax2.bar(algorithm_names, comps, color=sns.color_palette("colorblind"))
        ax2.set_title(f'Número de Comparações (Tamanho {size})')
        ax2.set_ylabel('Comparações')
        
        # Adicionar valores nas barras
        for bar in bars2:
            height = bar.get_height()
            value_text = f"{int(height):,}".replace(',', '.')
            ax2.text(bar.get_x() + bar.get_width()/2., height + height*0.05,
                    value_text, ha='center', va='bottom', rotation=0)
        
        # 3. Movimentações
        moves = []
        for algorithm in algorithms:
            col_name = f"{algorithm}_movements"
            moves.append(size_data[col_name].values[0])
        
        bars3 = ax3.bar(algorithm_names, moves, color=sns.color_palette("colorblind"))
        ax3.set_title(f'Número de Movimentações (Tamanho {size})')
        ax3.set_ylabel('Movimentações')
        
        # Adicionar valores nas barras
        for bar in bars3:
            height = bar.get_height()
            value_text = f"{int(height):,}".replace(',', '.')
            ax3.text(bar.get_x() + bar.get_width()/2., height + height*0.05,
                    value_text, ha='center', va='bottom', rotation=0)
        
        plt.tight_layout()
        plt.savefig(os.path.join(output_dir, f'comparacao_tamanho_{size}.png'), dpi=300, bbox_inches='tight')
        print(f"Gráfico comparativo para tamanho {size} salvo em {output_dir}/comparacao_tamanho_{size}.png")
        plt.close(fig)

def create_comparison_table(df, output_dir):
    """Cria uma tabela comparativa com os resultados finais"""
    # Criar tabela para cada tamanho
    for size in df['size'].values:
        size_data = df[df['size'] == size]
        
        # Preparar dados para a tabela
        algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort', 'quick_sort']
        algorithm_names = [algo.replace('_', ' ').title() for algo in algorithms]
        
        data = []
        for algorithm in algorithms:
            time_col = f"{algorithm}_execution_time_s"
            comp_col = f"{algorithm}_comparisons"
            move_col = f"{algorithm}_movements"
            
            time_val = size_data[time_col].values[0]
            comp_val = size_data[comp_col].values[0]
            move_val = size_data[move_col].values[0]
            
            # Substituir infinito por "N/A"
            time_str = "N/A" if np.isinf(time_val) else f"{time_val:.6f} s"
            
            # Formatar números grandes
            comp_str = f"{int(comp_val):,}".replace(',', '.')
            move_str = f"{int(move_val):,}".replace(',', '.')
            
            data.append([time_str, comp_str, move_str])
        
        # Criar tabela com pandas
        table_df = pd.DataFrame(data, 
                               index=algorithm_names,
                               columns=['Tempo (s)', 'Comparações', 'Movimentações'])
        
        # Salvar tabela como CSV
        csv_path = os.path.join(output_dir, f'tabela_comparativa_{size}.csv')
        table_df.to_csv(csv_path)
        print(f"Tabela comparativa para tamanho {size} salva em {csv_path}")
        
        # Criar tabela visual
        fig, ax = plt.subplots(figsize=(10, 6))
        ax.axis('off')
        table = ax.table(
            cellText=table_df.values,
            rowLabels=table_df.index,
            colLabels=table_df.columns,
            cellLoc='center',
            loc='center'
        )
        table.auto_set_font_size(False)
        table.set_fontsize(12)
        table.scale(1.2, 1.5)
        
        plt.title(f'Comparação de Algoritmos de Ordenação (Tamanho {size})', fontsize=14)
        plt.tight_layout()
        plt.savefig(os.path.join(output_dir, f'tabela_comparativa_{size}.png'), 
                   dpi=300, bbox_inches='tight')
        print(f"Imagem da tabela comparativa para tamanho {size} salva em {output_dir}/tabela_comparativa_{size}.png")
        plt.close(fig)

def plot_comprehensive_comparison(df, output_dir):
    """Plota um gráfico completo que contempla todos os casos e algoritmos"""
    # Lista de algoritmos
    algorithms = ['selection_sort', 'insertion_sort', 'bubble_sort', 'quick_sort']
    algorithm_names = [algo.replace('_', ' ').title() for algo in algorithms]
    
    # Criar uma figura grande com várias subplots
    fig = plt.figure(figsize=(16, 12))
    gs = GridSpec(3, 4, figure=fig)
    
    # Título principal
    fig.suptitle('Comparação Completa dos Algoritmos de Ordenação', fontsize=16)
    
    # 1. Gráfico de tempo de execução (toda a primeira linha)
    ax_time = fig.add_subplot(gs[0, :])
    for algorithm in algorithms:
        col_name = f"{algorithm}_execution_time_s"
        values = df[col_name].values
        values = np.where(np.isinf(values), np.nan, values)
        ax_time.plot(df['size'].values, values, marker='o', linewidth=2, 
                   label=algorithm.replace('_', ' ').title())
    
    ax_time.set_title('Tempo de Execução vs. Tamanho do Array')
    ax_time.set_xlabel('Tamanho do Array')
    ax_time.set_ylabel('Tempo (segundos)')
    ax_time.legend()
    ax_time.grid(True)
    
    # 2. Gráfico de comparações (2a linha, 2 primeiras colunas)
    ax_comp = fig.add_subplot(gs[1, :2])
    for algorithm in algorithms:
        col_name = f"{algorithm}_comparisons"
        ax_comp.plot(df['size'].values, df[col_name].values, marker='o', linewidth=2, 
                    label=algorithm.replace('_', ' ').title())
    
    ax_comp.set_title('Número de Comparações vs. Tamanho do Array')
    ax_comp.set_xlabel('Tamanho do Array')
    ax_comp.set_ylabel('Comparações')
    ax_comp.legend()
    ax_comp.grid(True)
    
    # 3. Gráfico de movimentações (2a linha, 2 últimas colunas)
    ax_move = fig.add_subplot(gs[1, 2:])
    for algorithm in algorithms:
        col_name = f"{algorithm}_movements"
        ax_move.plot(df['size'].values, df[col_name].values, marker='o', linewidth=2, 
                    label=algorithm.replace('_', ' ').title())
    
    ax_move.set_title('Número de Movimentações vs. Tamanho do Array')
    ax_move.set_xlabel('Tamanho do Array')
    ax_move.set_ylabel('Movimentações')
    ax_move.legend()
    ax_move.grid(True)
    
    # 4. Gráficos de barras para o maior tamanho (3a linha)
    size = df['size'].max()
    size_data = df[df['size'] == size]
    
    # 4.1 Tempo (3a linha, 1a coluna)
    ax_time_bar = fig.add_subplot(gs[2, 0])
    times = []
    for algorithm in algorithms:
        col_name = f"{algorithm}_execution_time_s"
        value = size_data[col_name].values[0]
        times.append(float('nan') if np.isinf(value) else value)
    
    ax_time_bar.bar(algorithm_names, times, color=sns.color_palette("colorblind")[:4])
    ax_time_bar.set_title(f'Tempo (Tamanho {size})')
    ax_time_bar.set_ylabel('Segundos')
    plt.setp(ax_time_bar.get_xticklabels(), rotation=45, ha='right')
    
    # 4.2 Comparações (3a linha, 2a coluna)
    ax_comp_bar = fig.add_subplot(gs[2, 1])
    comps = []
    for algorithm in algorithms:
        col_name = f"{algorithm}_comparisons"
        comps.append(size_data[col_name].values[0])
    
    ax_comp_bar.bar(algorithm_names, comps, color=sns.color_palette("colorblind")[:4])
    ax_comp_bar.set_title(f'Comparações (Tamanho {size})')
    plt.setp(ax_comp_bar.get_xticklabels(), rotation=45, ha='right')
    
    # 4.3 Movimentações (3a linha, 3a coluna)
    ax_move_bar = fig.add_subplot(gs[2, 2])
    moves = []
    for algorithm in algorithms:
        col_name = f"{algorithm}_movements"
        moves.append(size_data[col_name].values[0])
    
    ax_move_bar.bar(algorithm_names, moves, color=sns.color_palette("colorblind")[:4])
    ax_move_bar.set_title(f'Movimentações (Tamanho {size})')
    plt.setp(ax_move_bar.get_xticklabels(), rotation=45, ha='right')
    
    # 4.4 Eficiência relativa (tempo / comparações) (3a linha, 4a coluna)
    ax_eff = fig.add_subplot(gs[2, 3])
    effs = []
    for algorithm in algorithms:
        time_col = f"{algorithm}_execution_time_s"
        comp_col = f"{algorithm}_comparisons"
        time_val = size_data[time_col].values[0]
        comp_val = size_data[comp_col].values[0]
        
        # Se o tempo é infinito, a eficiência é 0
        if np.isinf(time_val):
            effs.append(0)
        else:
            # Quanto menor o tempo por comparação, maior a eficiência
            eff = 1 / (time_val / comp_val)
            effs.append(eff)
    
    # Normalizar eficiência para escala [0,1]
    if max(effs) > 0:
        effs = [e / max(effs) for e in effs]
    
    ax_eff.bar(algorithm_names, effs, color=sns.color_palette("colorblind")[:4])
    ax_eff.set_title(f'Eficiência Relativa (Tamanho {size})')
    ax_eff.set_ylabel('Eficiência (Normalizada)')
    plt.setp(ax_eff.get_xticklabels(), rotation=45, ha='right')
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, 'comparacao_completa.png'), dpi=300, bbox_inches='tight')
    print(f"Gráfico de comparação completa salvo em {output_dir}/comparacao_completa.png")
    plt.close(fig)

def create_all_visualizations(results_dir, output_dir):
    """Cria todas as visualizações"""
    # Verificar se o diretório de saída existe, se não, criar
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
        print(f"Diretório de saída criado: {output_dir}")
    
    # Carregar resultados
    results_df = load_results(results_dir)
    
    # Criar visualizações expandidas
    plot_execution_times(results_df, output_dir)
    plot_individual_execution_times(results_df, output_dir)
    plot_comparisons(results_df, output_dir)
    plot_individual_comparisons(results_df, output_dir)
    plot_movements(results_df, output_dir)
    plot_individual_movements(results_df, output_dir)
    plot_combined_metrics(results_df, output_dir)  # Nova função para métricas combinadas
    plot_bars_comparison(results_df, output_dir)
    create_comparison_table(results_df, output_dir)
    plot_comprehensive_comparison(results_df, output_dir)
    
    print("\nTodas as visualizações foram criadas com sucesso!")
    print(f"Total de arquivos gerados: {len(os.listdir(output_dir)) + len(os.listdir(os.path.join(output_dir, 'individuais')))}")

if __name__ == "__main__":
    # Teste direto
    create_all_visualizations("../results", "../visualizations")