__author__ = 'anonymous'
from loader import Loader
import json
class ConfigLoader(Loader):

    def __init__(self,path,override=None):
        super().__init__(path,override)


    def get(self,val):
        if not val:
            raise ValueError("String seems to be empty")
        path = [i for i in val.split('.') if i.strip()]
        config = self._config
        for p in path:
            if config:
                config = config.get(p)
        return json.dumps(config,indent=2,separators=(',',' == '))
