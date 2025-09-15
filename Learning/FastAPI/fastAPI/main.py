import time

from fastapi import FastAPI,Request

app = FastAPI()

@app.middleware("http")
async def add_process_time_header(request: Request,call_next):
    start_time = time.time()
    response = await call_next(request)
    process_time = time.perf_counter() - start_time
    response.headers["X-Process_Time"] = str(porcess_time)
    return response