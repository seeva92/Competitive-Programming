__author__ = 'anonymous'
from config_loader import ConfigLoader
import json
def main():
    loader = ConfigLoader("config.ini",['ubuntu','staging','development'])
    print(loader.get('ftp'))
    print(loader.get('ftp.name'))
    print(loader.get('ftp.enabled'))
    print(loader.get('poda'))
    print(loader.get('common'))
    print(loader.get('common.basic_size_limit'))

if __name__ == "__main__":
    main()

