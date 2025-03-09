import os
import re

def get_english_title(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()
        # Look for the problem URL
        match = re.search(r'https://leetcode.cn/problems/([^/]+)/', content)
        if match:
            # Convert kebab-case to title
            title = match.group(1).replace('-', ' ').title()
            # Convert back to kebab-case
            return '-'.join(title.lower().split())
    return None

def main():
    directory = os.path.dirname(os.path.abspath(__file__))
    for filename in os.listdir(directory):
        if filename.endswith('.cpp'):
            # Check if filename contains Chinese characters
            if any('\u4e00' <= c <= '\u9fff' for c in filename):
                file_path = os.path.join(directory, filename)
                # Extract problem number
                number_match = re.match(r'(\d+)-', filename)
                if number_match:
                    problem_number = number_match.group(1)
                    # Get English title
                    english_title = get_english_title(file_path)
                    if english_title:
                        new_filename = f"{problem_number}-{english_title}.cpp"
                        try:
                            os.rename(file_path, os.path.join(directory, new_filename))
                            print(f"Renamed: {filename} -> {new_filename}")
                        except Exception as e:
                            print(f"Error renaming {filename}: {e}")

if __name__ == '__main__':
    main() 